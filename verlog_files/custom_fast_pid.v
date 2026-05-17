`timescale 1ns / 1ps

module custom_fast_pid #(
    // Bit-width definitions
    parameter DATA_WIDTH  = 32, // Width of timestamp counters
    parameter COEFF_WIDTH = 16, // Width of Kp, Ki, Kd registers
    parameter OUT_WIDTH   = 16, // DAC output width (e.g., 16-bit DAC)
    parameter SHIFT_VAL   = 10, // Arithmetic right-shift for fractional scaling (Q format)
    
    // Saturation limits to prevent mechanical stress or digital wrap-around
    parameter signed MAX_INT = 32'sd500000,
    parameter signed MIN_INT = -32'sd500000,
    parameter signed MAX_OUT = 16'sd32767,
    parameter signed MIN_OUT = -16'sd32768
)(
    input  wire clk,
    input  wire rst_n,
    
    // Strobe from Arithmetic Pre-Processor (1 clock cycle wide)
    input  wire new_data_i, 
    
    // Inputs (Target and Actual Timestamps)
    input  wire signed [DATA_WIDTH-1:0] scan_start_target_i, // Setpoint
    input  wire signed [DATA_WIDTH-1:0] reg_master_peak_1_i, // Actual
    
    // Tunable PID Coefficients
    input  wire signed [COEFF_WIDTH-1:0] kp_i,
    input  wire signed [COEFF_WIDTH-1:0] ki_i,
    input  wire signed [COEFF_WIDTH-1:0] kd_i,
    
    // Final Actuator Output
    output reg  signed [OUT_WIDTH-1:0] dac_out_o
);

    // --------------------------------------------------------
    // State Persistence Registers (Hold value between 3kHz sweeps)
    // --------------------------------------------------------
    reg signed [DATA_WIDTH-1:0] prev_error;
    reg signed [DATA_WIDTH-1:0] integrator;

    // --------------------------------------------------------
    // Pipeline Registers
    // --------------------------------------------------------
    reg [4:0] valid_pipe;

    // Cycle 1
    reg signed [DATA_WIDTH-1:0] p1_error;
    reg signed [DATA_WIDTH-1:0] p1_error_diff;

    // Cycle 2 (Multiplication requires expanded bit width)
    reg signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_p_term_raw;
    reg signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_i_term_raw;
    reg signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_d_term_raw;

    // --- FIX FOR WIDTHTRUNC ---
    // Explicitly shift and slice the multiplier output from 48 bits back to 32 bits
    wire signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_p_shifted_raw = p2_p_term_raw >>> SHIFT_VAL;
    wire signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_i_shifted_raw = p2_i_term_raw >>> SHIFT_VAL;
    wire signed [DATA_WIDTH+COEFF_WIDTH-1:0] p2_d_shifted_raw = p2_d_term_raw >>> SHIFT_VAL;

    wire signed [DATA_WIDTH-1:0] p2_p_shifted = p2_p_shifted_raw[DATA_WIDTH-1:0];
    wire signed [DATA_WIDTH-1:0] p2_i_shifted = p2_i_shifted_raw[DATA_WIDTH-1:0];
    wire signed [DATA_WIDTH-1:0] p2_d_shifted = p2_d_shifted_raw[DATA_WIDTH-1:0];

    // Cycle 3
    reg signed [DATA_WIDTH-1:0] p3_p_term;
    reg signed [DATA_WIDTH-1:0] p3_i_term;
    reg signed [DATA_WIDTH-1:0] p3_d_term;

    // Cycle 4
    reg signed [DATA_WIDTH-1:0] p4_integrator_next;

    // Cycle 5
    reg signed [DATA_WIDTH-1:0] p5_pid_sum;

    // Constants for padding (Fix for WIDTHEXPAND comparing 32-bit sum to 16-bit limits)
    localparam PAD_OUT = DATA_WIDTH - OUT_WIDTH;

    // --------------------------------------------------------
    // Pipelined Execution Block
    // --------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            valid_pipe <= 5'b0;
            prev_error <= 0;
            integrator <= 0;
            dac_out_o  <= 0;
            
            // Clear pipeline registers safely
            p1_error <= 0;
            p1_error_diff <= 0;
            p2_p_term_raw <= 0;
            p2_i_term_raw <= 0;
            p2_d_term_raw <= 0;
            p3_p_term <= 0;
            p3_i_term <= 0;
            p3_d_term <= 0;
            p4_integrator_next <= 0;
            p5_pid_sum <= 0;
        end else begin
            // Shift the enable bubble through the pipeline
            valid_pipe <= {valid_pipe[3:0], new_data_i};

            // --------------------------------------------------------
            // Cycle 1: Error Calculation
            // --------------------------------------------------------
            if (new_data_i) begin
                p1_error      <= scan_start_target_i - reg_master_peak_1_i;
                p1_error_diff <= (scan_start_target_i - reg_master_peak_1_i) - prev_error;
                
                // Update persistent state
                prev_error    <= scan_start_target_i - reg_master_peak_1_i;
            end

            // --------------------------------------------------------
            // Cycle 2: Parallel Multiplication (Maps to DSP48 slices)
            // --------------------------------------------------------
            if (valid_pipe[0]) begin
                p2_p_term_raw <= p1_error      * kp_i;
                p2_i_term_raw <= p1_error      * ki_i;
                p2_d_term_raw <= p1_error_diff * kd_i;
            end

            // --------------------------------------------------------
            // Cycle 3: Gain Scaling (Arithmetic Right Shift)
            // --------------------------------------------------------
            if (valid_pipe[1]) begin
                // Use explicitly sliced wires to prevent WIDTHTRUNC
                p3_p_term <= p2_p_shifted;
                p3_i_term <= p2_i_shifted;
                p3_d_term <= p2_d_shifted;
            end

            // --------------------------------------------------------
            // Cycle 4: Integral Accumulation & Anti-Windup
            // --------------------------------------------------------
            if (valid_pipe[2]) begin
                // FIX FOR WIDTHEXPAND: Extend parameter components to 33 bits for addition
                automatic logic signed [DATA_WIDTH:0] ext_integrator = {integrator[DATA_WIDTH-1], integrator};
                automatic logic signed [DATA_WIDTH:0] ext_p3_i_term  = {p3_i_term[DATA_WIDTH-1], p3_i_term};
                automatic logic signed [DATA_WIDTH:0] temp_int       = ext_integrator + ext_p3_i_term;
                
                automatic logic signed [DATA_WIDTH:0] ext_max_int    = {MAX_INT[31], MAX_INT};
                automatic logic signed [DATA_WIDTH:0] ext_min_int    = {MIN_INT[31], MIN_INT};

                // Clamp to prevent windup
                if (temp_int > ext_max_int) begin
                    integrator <= MAX_INT;
                    p4_integrator_next <= MAX_INT;
                end else if (temp_int < ext_min_int) begin
                    integrator <= MIN_INT;
                    p4_integrator_next <= MIN_INT;
                end else begin
                    integrator <= temp_int[DATA_WIDTH-1:0];
                    p4_integrator_next <= temp_int[DATA_WIDTH-1:0];
                end
            end

            // --------------------------------------------------------
            // Cycle 5: Summation
            // --------------------------------------------------------
            if (valid_pipe[3]) begin
                p5_pid_sum <= p3_p_term + p4_integrator_next + p3_d_term;
            end

            // --------------------------------------------------------
            // Cycle 6: Output Saturation and DAC Register Update
            // --------------------------------------------------------
            if (valid_pipe[4]) begin
                // FIX FOR WIDTHEXPAND: Extend 16-bit thresholds to 32 bits for direct comparison
                automatic logic signed [DATA_WIDTH-1:0] ext_max_out = { {PAD_OUT{MAX_OUT[15]}}, MAX_OUT };
                automatic logic signed [DATA_WIDTH-1:0] ext_min_out = { {PAD_OUT{MIN_OUT[15]}}, MIN_OUT };

                if (p5_pid_sum > ext_max_out) 
                    dac_out_o <= MAX_OUT;
                else if (p5_pid_sum < ext_min_out) 
                    dac_out_o <= MIN_OUT;
                else 
                    dac_out_o <= p5_pid_sum[OUT_WIDTH-1:0];
            end

        end
    end

endmodule