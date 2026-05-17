import matplotlib.pyplot as plt

# Initialize arrays
target_ts = []
actual_ts = []
expected_dac = []
verilog_dac = []
sample_index = []

# Read the simulated data
with open("verilog_outputs.txt", "r") as f:
    idx = 0
    for line in f:
        if line.startswith("#"):
            continue
            
        parts = line.split()
        if len(parts) == 7:
            t_ts = int(parts[0])
            a_ts = int(parts[1])
            exp_dac = int(parts[5])
            ver_dac = int(parts[6])
            
            target_ts.append(t_ts)
            actual_ts.append(a_ts)
            expected_dac.append(exp_dac)
            verilog_dac.append(ver_dac)
            sample_index.append(idx)
            idx += 1

# --- Figure 1: Output Comparison Trajectory ---
plt.figure(figsize=(10, 5))
plt.plot(sample_index, expected_dac, label='MATLAB Expected (Golden)', linewidth=3, alpha=0.6, color='blue')
plt.plot(sample_index, verilog_dac, label='Verilog RTL Output', linestyle='--', linewidth=2, color='orange')
plt.title('PID DAC Command Comparison')
plt.xlabel('Sample Index (3 kHz Sweeps)')
plt.ylabel('DAC Value')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('pid_output_comparison.png')
plt.close() # Close to free up memory

# --- Calculation of Output Error ---
# This calculates the mismatch between your fixed-point reference and actual hardware
output_error = [rtl - matlab for rtl, matlab in zip(verilog_dac, expected_dac)]

# --- Figure 2: Output Error Trajectory ---
plt.figure(figsize=(10, 5))
plt.plot(sample_index, output_error, label='Output Residual (RTL - MATLAB)', color='red', linewidth=2)
plt.title('RTL Output Error vs. Golden Reference')
plt.xlabel('Sample Index (3 kHz Sweeps)')
plt.ylabel('Error Value (LSB Count)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('pid_output_error.png')
plt.close()

print("Plot processing complete.")
print("Saved: pid_output_comparison.png")
print("Saved: pid_output_error.png")