import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly

@cocotb.test()
async def test_pid_golden_match(dut):
    """Feed timestamps to the pipelined PID controller and save the RTL output."""
    
    cocotb.start_soon(Clock(dut.clk, 8, unit="ns").start())
    
    # Open input and output files
    with open("test_datasets/golden_vectors.txt", "r") as f_in, \
         open("output/verilog_outputs.txt", "w") as f_out:
             
        lines = f_in.readlines()
        
        # Write header to output file
        f_out.write("# target_ts actual_ts kp ki kd expected_dac_out verilog_dac_out\n")
        
        # Initial Reset (Updated to match custom_gated_pid ports)
        dut.rst_n.value = 0
        dut.new_data_i.value = 0
        dut.scan_start_target_i.value = 0
        dut.reg_master_peak_1_i.value = 0
        dut.kp_i.value = 0
        dut.ki_i.value = 0
        dut.kd_i.value = 0
        
        await RisingEdge(dut.clk)
        dut.rst_n.value = 1
        await RisingEdge(dut.clk)
        
        for line in lines:
            if line.startswith("#"):
                continue
                
            parts = line.split()
            if len(parts) != 6:
                continue
                
            # Parse the golden vector line
            target_ts = int(parts[0])
            actual_ts = int(parts[1])
            kp = int(parts[2])
            ki = int(parts[3])
            kd = int(parts[4])
            expected_out = int(parts[5])
            
            # Apply raw timestamps directly to DUT (Verilog does the subtraction now)
            dut.scan_start_target_i.value = target_ts
            dut.reg_master_peak_1_i.value = actual_ts
            dut.kp_i.value = kp
            dut.ki_i.value = ki
            dut.kd_i.value = kd
            
            # Pulse the new data strobe to start the pipeline
            dut.new_data_i.value = 1
            await RisingEdge(dut.clk)
            dut.new_data_i.value = 0
            
            # Wait for the pipeline to finish (Exactly 5 clock cycles)
            for _ in range(5):
                await RisingEdge(dut.clk)
                
            # Enter ReadOnly to safely sample the output
            await ReadOnly() 
            verilog_out = dut.dac_out_o.value.to_signed()
            
            # Save the transaction to the output file
            f_out.write(f"{target_ts} {actual_ts} {kp} {ki} {kd} {expected_out} {verilog_out}\n")
            
            # Step out of ReadOnly before the next loop
            await RisingEdge(dut.clk)

    dut._log.info("Simulation complete. Results saved to verilog_outputs.txt")