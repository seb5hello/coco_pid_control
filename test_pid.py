import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

@cocotb.test()
async def pid_basic_test(dut):
    """Test for PID controller basic functionality"""

    # Create a 10ns period clock on port clk
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst.value = 1
    dut.setpoint.value = 0
    dut.feedback.value = 0
    dut.kp.value = 0
    dut.ki.value = 0
    dut.kd.value = 0
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Test Proportional only
    dut.kp.value = 2
    dut.setpoint.value = 100
    dut.feedback.value = 50
    
    # Wait a few cycles
    for _ in range(5):
        await RisingEdge(dut.clk)
        dut._log.info(f"Setpoint: {dut.setpoint.value}, Feedback: {dut.feedback.value}, Out: {dut.control_out.value}")

    # Expected error = 100 - 50 = 50
    # Expected output (simplified) = kp * error = 2 * 50 = 100
    # Note: Our Verilog implementation has 1 cycle latency for error calculation 
    # and another for control_out calculation.
    
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    
    current_out = dut.control_out.value.integer
    dut._log.info(f"Final Control Out: {current_out}")
    
    # Check if it's moving in the right direction
    assert current_out > 0, "Control output should be positive for positive error"
