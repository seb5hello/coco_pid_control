`timescale 1ns/1ps

module data_rx #(
    RESOLUTION = 12,
    PRECISION = 0.0625
)(
    input clk,
    input reset,
    input [RESOLUTION+3:0] data_in,
    output [2:0] warn_sig,
    output signed [RESOLUTION:0] temp
);

    assign warn_sig = data_in[RESOLUTION+3:RESOLUTION+1];
    assign temp = data_in[RESOLUTION:0]*PRECISION;
    
endmodule