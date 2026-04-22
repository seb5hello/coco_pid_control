`timescale 1ns/1ps

module pwm #(
    parameter RESOLUTION = 16 // Added 'parameter' keyword
)(
    input  wire                  clk_in,
    input  wire                  reset,
    input  wire [RESOLUTION-1:0] duty,
    output reg                   pwm_sig
);

    reg [RESOLUTION-1:0] counter;

    always @(posedge clk_in) begin // Fixed signal name to clk_in
        if (reset) begin
            counter <= 0;         // Fixed: changed >= to <=
            pwm_sig <= 0;         // Fixed: changed >= to <=
        end else begin
            counter <= counter + 1; // Fixed: changed >= to <=
            
            if (counter < duty) begin
                pwm_sig <= 1'b1;
            end else begin
                pwm_sig <= 1'b0;
            end
        end
    end

endmodule
