module pid_controller (
    input clk,
    input rst,
    input signed [15:0] setpoint,
    input signed [15:0] feedback,
    input signed [15:0] kp,
    input signed [15:0] ki,
    input signed [15:0] kd,
    output reg signed [15:0] control_out
);

    reg signed [15:0] error;
    reg signed [15:0] integral;
    reg signed [15:0] last_error;
    wire signed [15:0] derivative;

    assign derivative = error - last_error;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            error <= 0;
            integral <= 0;
            last_error <= 0;
            control_out <= 0;
        end else begin
            error <= setpoint - feedback;
            integral <= integral + error;
            last_error <= error;
            control_out <= (kp * error) + (ki * integral) + (kd * derivative);
        end
    end

endmodule
