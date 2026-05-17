// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.new_data_i));
    bufp->chgIData(oldp+3,(vlSelfRef.scan_start_target_i),32);
    bufp->chgIData(oldp+4,(vlSelfRef.reg_master_peak_1_i),32);
    bufp->chgSData(oldp+5,(vlSelfRef.kp_i),16);
    bufp->chgSData(oldp+6,(vlSelfRef.ki_i),16);
    bufp->chgSData(oldp+7,(vlSelfRef.kd_i),16);
    bufp->chgSData(oldp+8,(vlSelfRef.dac_out_o),16);
    bufp->chgBit(oldp+9,(vlSelfRef.custom_gated_pid__DOT__clk));
    bufp->chgBit(oldp+10,(vlSelfRef.custom_gated_pid__DOT__rst_n));
    bufp->chgBit(oldp+11,(vlSelfRef.custom_gated_pid__DOT__new_data_i));
    bufp->chgIData(oldp+12,(vlSelfRef.custom_gated_pid__DOT__scan_start_target_i),32);
    bufp->chgIData(oldp+13,(vlSelfRef.custom_gated_pid__DOT__reg_master_peak_1_i),32);
    bufp->chgSData(oldp+14,(vlSelfRef.custom_gated_pid__DOT__kp_i),16);
    bufp->chgSData(oldp+15,(vlSelfRef.custom_gated_pid__DOT__ki_i),16);
    bufp->chgSData(oldp+16,(vlSelfRef.custom_gated_pid__DOT__kd_i),16);
    bufp->chgSData(oldp+17,(vlSelfRef.custom_gated_pid__DOT__dac_out_o),16);
    bufp->chgIData(oldp+18,(vlSelfRef.custom_gated_pid__DOT__prev_error),32);
    bufp->chgIData(oldp+19,(vlSelfRef.custom_gated_pid__DOT__integrator),32);
    bufp->chgCData(oldp+20,(vlSelfRef.custom_gated_pid__DOT__valid_pipe),5);
    bufp->chgIData(oldp+21,(vlSelfRef.custom_gated_pid__DOT__p1_error),32);
    bufp->chgIData(oldp+22,(vlSelfRef.custom_gated_pid__DOT__p1_error_diff),32);
    bufp->chgQData(oldp+23,(vlSelfRef.custom_gated_pid__DOT__p2_p_term_raw),48);
    bufp->chgQData(oldp+25,(vlSelfRef.custom_gated_pid__DOT__p2_i_term_raw),48);
    bufp->chgQData(oldp+27,(vlSelfRef.custom_gated_pid__DOT__p2_d_term_raw),48);
    bufp->chgQData(oldp+29,(vlSelfRef.custom_gated_pid__DOT__p2_p_shifted_raw),48);
    bufp->chgQData(oldp+31,(vlSelfRef.custom_gated_pid__DOT__p2_i_shifted_raw),48);
    bufp->chgQData(oldp+33,(vlSelfRef.custom_gated_pid__DOT__p2_d_shifted_raw),48);
    bufp->chgIData(oldp+35,(vlSelfRef.custom_gated_pid__DOT__p2_p_shifted),32);
    bufp->chgIData(oldp+36,(vlSelfRef.custom_gated_pid__DOT__p2_i_shifted),32);
    bufp->chgIData(oldp+37,(vlSelfRef.custom_gated_pid__DOT__p2_d_shifted),32);
    bufp->chgIData(oldp+38,(vlSelfRef.custom_gated_pid__DOT__p3_p_term),32);
    bufp->chgIData(oldp+39,(vlSelfRef.custom_gated_pid__DOT__p3_i_term),32);
    bufp->chgIData(oldp+40,(vlSelfRef.custom_gated_pid__DOT__p3_d_term),32);
    bufp->chgIData(oldp+41,(vlSelfRef.custom_gated_pid__DOT__p4_integrator_next),32);
    bufp->chgIData(oldp+42,(vlSelfRef.custom_gated_pid__DOT__p5_pid_sum),32);
    bufp->chgQData(oldp+43,(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator),33);
    bufp->chgQData(oldp+45,(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term),33);
    bufp->chgQData(oldp+47,(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int),33);
    bufp->chgQData(oldp+49,(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int),33);
    bufp->chgQData(oldp+51,(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int),33);
    bufp->chgIData(oldp+53,(vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out),32);
    bufp->chgIData(oldp+54,(vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
