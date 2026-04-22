`timescale 1ns/1ps

module pid_top (
    input clk,
    input rst,
    input signed [15:0] setpoint,
    input signed [15:0] feedback,
    input signed [15:0] kp,
    input signed [15:0] ki,
    input signed [15:0] kd,
    output reg signed [15:0] control_out
);

    // Instantiate the PWM module
    data_rx #(
        .RESOLUTION(12)           // Passing the parameter value
        .PRECISION(0.0625)        // Passing the parameter value
    ) data_rx_inst (
        .clk_in     (clk),      // Connect to system clock
        .reset      (rst),      // Connect to system reset
        .data_in    (feedback), // The 16-bit 
        .warn_sig   (),         // 
        .temp       ()          // 
    );

    // Instantiate the PWM module
    pwm #(
        .RESOLUTION(12)           // Passing the parameter value
    ) pwm_inst (
        .clk_in  (clk),           // Connect to system clock
        .reset   (rst),     // Connect to system reset
        .duty    (pid_to_pwm_duty), // The 16-bit output from your PID
        .pwm_sig (system_pwm_out)  // The physical output pin
    ); 
    
    // Calculate error value for PID module
    // reg signed [15:0] error;
    // error = temp - setpoint;

    pid #(
        .RESOLUTION(12)           // Passing the parameter value
    ) pid_inst (
        .clk_in  (clk),           // Connect to system clock
        .reset   (rst),     // Connect to system reset
        .error    (), // 
        .kp (),  // 
        .ki (),  // 
        .kd (),  // 
        .output_val ()  // 
    );
    
endmodule
