// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_custom_gated_pid);
    __Vhier.remove(&__Vscope_custom_gated_pid, &__Vscope_custom_gated_pid__unnamedblk1);
    __Vhier.remove(&__Vscope_custom_gated_pid, &__Vscope_custom_gated_pid__unnamedblk2);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(67);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_custom_gated_pid.configure(this, name(), "custom_gated_pid", "custom_gated_pid", "custom_gated_pid", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_custom_gated_pid__unnamedblk1.configure(this, name(), "custom_gated_pid.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_custom_gated_pid__unnamedblk2.configure(this, name(), "custom_gated_pid.unnamedblk2", "unnamedblk2", "<null>", -9, VerilatedScope::SCOPE_OTHER);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_custom_gated_pid);
    __Vhier.add(&__Vscope_custom_gated_pid, &__Vscope_custom_gated_pid__unnamedblk1);
    __Vhier.add(&__Vscope_custom_gated_pid, &__Vscope_custom_gated_pid__unnamedblk2);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dac_out_o", &(TOP.dac_out_o), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"kd_i", &(TOP.kd_i), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"ki_i", &(TOP.ki_i), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"kp_i", &(TOP.kp_i), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"new_data_i", &(TOP.new_data_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"reg_master_peak_1_i", &(TOP.reg_master_peak_1_i), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"scan_start_target_i", &(TOP.scan_start_target_i), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"COEFF_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__COEFF_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"MAX_INT", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__MAX_INT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"MAX_OUT", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__MAX_OUT))), true, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"MIN_INT", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__MIN_INT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"MIN_OUT", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__MIN_OUT))), true, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"OUT_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__OUT_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"PAD_OUT", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__PAD_OUT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"SHIFT_VAL", const_cast<void*>(static_cast<const void*>(&(TOP.custom_gated_pid__DOT__SHIFT_VAL))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"clk", &(TOP.custom_gated_pid__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"dac_out_o", &(TOP.custom_gated_pid__DOT__dac_out_o), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"integrator", &(TOP.custom_gated_pid__DOT__integrator), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"kd_i", &(TOP.custom_gated_pid__DOT__kd_i), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"ki_i", &(TOP.custom_gated_pid__DOT__ki_i), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"kp_i", &(TOP.custom_gated_pid__DOT__kp_i), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"new_data_i", &(TOP.custom_gated_pid__DOT__new_data_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p1_error", &(TOP.custom_gated_pid__DOT__p1_error), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p1_error_diff", &(TOP.custom_gated_pid__DOT__p1_error_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_d_shifted", &(TOP.custom_gated_pid__DOT__p2_d_shifted), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_d_shifted_raw", &(TOP.custom_gated_pid__DOT__p2_d_shifted_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_d_term_raw", &(TOP.custom_gated_pid__DOT__p2_d_term_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_i_shifted", &(TOP.custom_gated_pid__DOT__p2_i_shifted), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_i_shifted_raw", &(TOP.custom_gated_pid__DOT__p2_i_shifted_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_i_term_raw", &(TOP.custom_gated_pid__DOT__p2_i_term_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_p_shifted", &(TOP.custom_gated_pid__DOT__p2_p_shifted), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_p_shifted_raw", &(TOP.custom_gated_pid__DOT__p2_p_shifted_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p2_p_term_raw", &(TOP.custom_gated_pid__DOT__p2_p_term_raw), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p3_d_term", &(TOP.custom_gated_pid__DOT__p3_d_term), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p3_i_term", &(TOP.custom_gated_pid__DOT__p3_i_term), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p3_p_term", &(TOP.custom_gated_pid__DOT__p3_p_term), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p4_integrator_next", &(TOP.custom_gated_pid__DOT__p4_integrator_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"p5_pid_sum", &(TOP.custom_gated_pid__DOT__p5_pid_sum), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"prev_error", &(TOP.custom_gated_pid__DOT__prev_error), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"reg_master_peak_1_i", &(TOP.custom_gated_pid__DOT__reg_master_peak_1_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"rst_n", &(TOP.custom_gated_pid__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"scan_start_target_i", &(TOP.custom_gated_pid__DOT__scan_start_target_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid.varInsert(__Vfinal,"valid_pipe", &(TOP.custom_gated_pid__DOT__valid_pipe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_custom_gated_pid__unnamedblk1.varInsert(__Vfinal,"ext_integrator", &(TOP.custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_custom_gated_pid__unnamedblk1.varInsert(__Vfinal,"ext_max_int", &(TOP.custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_custom_gated_pid__unnamedblk1.varInsert(__Vfinal,"ext_min_int", &(TOP.custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_custom_gated_pid__unnamedblk1.varInsert(__Vfinal,"ext_p3_i_term", &(TOP.custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_custom_gated_pid__unnamedblk1.varInsert(__Vfinal,"temp_int", &(TOP.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_custom_gated_pid__unnamedblk2.varInsert(__Vfinal,"ext_max_out", &(TOP.custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_custom_gated_pid__unnamedblk2.varInsert(__Vfinal,"ext_min_out", &(TOP.custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
    }
}
