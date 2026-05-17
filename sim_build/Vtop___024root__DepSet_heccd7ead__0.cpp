// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.custom_gated_pid__DOT__clk = vlSelfRef.clk;
    vlSelfRef.custom_gated_pid__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.custom_gated_pid__DOT__new_data_i = vlSelfRef.new_data_i;
    vlSelfRef.custom_gated_pid__DOT__scan_start_target_i 
        = vlSelfRef.scan_start_target_i;
    vlSelfRef.custom_gated_pid__DOT__reg_master_peak_1_i 
        = vlSelfRef.reg_master_peak_1_i;
    vlSelfRef.custom_gated_pid__DOT__kp_i = vlSelfRef.kp_i;
    vlSelfRef.custom_gated_pid__DOT__ki_i = vlSelfRef.ki_i;
    vlSelfRef.custom_gated_pid__DOT__kd_i = vlSelfRef.kd_i;
    vlSelfRef.dac_out_o = vlSelfRef.custom_gated_pid__DOT__dac_out_o;
    vlSelfRef.custom_gated_pid__DOT__p2_p_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_p_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_i_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_i_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_d_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_d_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_p_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_p_shifted_raw);
    vlSelfRef.custom_gated_pid__DOT__p2_i_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_i_shifted_raw);
    vlSelfRef.custom_gated_pid__DOT__p2_d_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_d_shifted_raw);
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vdly__custom_gated_pid__DOT__valid_pipe;
    __Vdly__custom_gated_pid__DOT__valid_pipe = 0;
    IData/*31:0*/ __Vdly__custom_gated_pid__DOT__p3_p_term;
    __Vdly__custom_gated_pid__DOT__p3_p_term = 0;
    IData/*31:0*/ __Vdly__custom_gated_pid__DOT__p3_i_term;
    __Vdly__custom_gated_pid__DOT__p3_i_term = 0;
    IData/*31:0*/ __Vdly__custom_gated_pid__DOT__p3_d_term;
    __Vdly__custom_gated_pid__DOT__p3_d_term = 0;
    IData/*31:0*/ __Vdly__custom_gated_pid__DOT__p4_integrator_next;
    __Vdly__custom_gated_pid__DOT__p4_integrator_next = 0;
    IData/*31:0*/ __Vdly__custom_gated_pid__DOT__p5_pid_sum;
    __Vdly__custom_gated_pid__DOT__p5_pid_sum = 0;
    // Body
    __Vdly__custom_gated_pid__DOT__valid_pipe = vlSelfRef.custom_gated_pid__DOT__valid_pipe;
    __Vdly__custom_gated_pid__DOT__p3_p_term = vlSelfRef.custom_gated_pid__DOT__p3_p_term;
    __Vdly__custom_gated_pid__DOT__p3_i_term = vlSelfRef.custom_gated_pid__DOT__p3_i_term;
    __Vdly__custom_gated_pid__DOT__p3_d_term = vlSelfRef.custom_gated_pid__DOT__p3_d_term;
    __Vdly__custom_gated_pid__DOT__p4_integrator_next 
        = vlSelfRef.custom_gated_pid__DOT__p4_integrator_next;
    __Vdly__custom_gated_pid__DOT__p5_pid_sum = vlSelfRef.custom_gated_pid__DOT__p5_pid_sum;
    if (vlSelfRef.rst_n) {
        __Vdly__custom_gated_pid__DOT__valid_pipe = 
            ((0x1eU & ((IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe) 
                       << 1U)) | (IData)(vlSelfRef.new_data_i));
        if ((1U & (IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe))) {
            vlSelfRef.custom_gated_pid__DOT__p2_p_term_raw 
                = (0xffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.custom_gated_pid__DOT__p1_error)), 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.kp_i)))));
            vlSelfRef.custom_gated_pid__DOT__p2_i_term_raw 
                = (0xffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.custom_gated_pid__DOT__p1_error)), 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.ki_i)))));
            vlSelfRef.custom_gated_pid__DOT__p2_d_term_raw 
                = (0xffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.custom_gated_pid__DOT__p1_error_diff)), 
                                                   (0xffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.kd_i)))));
        }
        if ((2U & (IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe))) {
            __Vdly__custom_gated_pid__DOT__p3_p_term 
                = vlSelfRef.custom_gated_pid__DOT__p2_p_shifted;
            __Vdly__custom_gated_pid__DOT__p3_i_term 
                = vlSelfRef.custom_gated_pid__DOT__p2_i_shifted;
            __Vdly__custom_gated_pid__DOT__p3_d_term 
                = vlSelfRef.custom_gated_pid__DOT__p2_d_shifted;
        }
        if ((4U & (IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe))) {
            vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator 
                = (((QData)((IData)((vlSelfRef.custom_gated_pid__DOT__integrator 
                                     >> 0x1fU))) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.custom_gated_pid__DOT__integrator)));
            vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term 
                = (((QData)((IData)((vlSelfRef.custom_gated_pid__DOT__p3_i_term 
                                     >> 0x1fU))) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.custom_gated_pid__DOT__p3_i_term)));
            vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int 
                = (0x1ffffffffULL & (vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator 
                                     + vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term));
            vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int = 0x7a120ULL;
            vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int = 0x1fff85ee0ULL;
            if (VL_GTS_IQQ(33, vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int, vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int)) {
                vlSelfRef.custom_gated_pid__DOT__integrator = 0x7a120U;
                __Vdly__custom_gated_pid__DOT__p4_integrator_next = 0x7a120U;
            } else if (VL_LTS_IQQ(33, vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int, vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int)) {
                vlSelfRef.custom_gated_pid__DOT__integrator = 0xfff85ee0U;
                __Vdly__custom_gated_pid__DOT__p4_integrator_next = 0xfff85ee0U;
            } else {
                vlSelfRef.custom_gated_pid__DOT__integrator 
                    = (IData)(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int);
                __Vdly__custom_gated_pid__DOT__p4_integrator_next 
                    = (IData)(vlSelfRef.custom_gated_pid__DOT__unnamedblk1__DOT__temp_int);
            }
        }
        if ((8U & (IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe))) {
            __Vdly__custom_gated_pid__DOT__p5_pid_sum 
                = ((vlSelfRef.custom_gated_pid__DOT__p3_p_term 
                    + vlSelfRef.custom_gated_pid__DOT__p4_integrator_next) 
                   + vlSelfRef.custom_gated_pid__DOT__p3_d_term);
        }
        if ((0x10U & (IData)(vlSelfRef.custom_gated_pid__DOT__valid_pipe))) {
            vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out = 0x7fffU;
            vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out = 0xffff8000U;
            vlSelfRef.custom_gated_pid__DOT__dac_out_o 
                = (VL_GTS_III(32, vlSelfRef.custom_gated_pid__DOT__p5_pid_sum, vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out)
                    ? 0x7fffU : (VL_LTS_III(32, vlSelfRef.custom_gated_pid__DOT__p5_pid_sum, vlSelfRef.custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out)
                                  ? 0x8000U : (0xffffU 
                                               & vlSelfRef.custom_gated_pid__DOT__p5_pid_sum)));
        }
        if (vlSelfRef.new_data_i) {
            vlSelfRef.custom_gated_pid__DOT__p1_error 
                = (vlSelfRef.scan_start_target_i - vlSelfRef.reg_master_peak_1_i);
            vlSelfRef.custom_gated_pid__DOT__p1_error_diff 
                = ((vlSelfRef.scan_start_target_i - vlSelfRef.reg_master_peak_1_i) 
                   - vlSelfRef.custom_gated_pid__DOT__prev_error);
            vlSelfRef.custom_gated_pid__DOT__prev_error 
                = (vlSelfRef.scan_start_target_i - vlSelfRef.reg_master_peak_1_i);
        }
    } else {
        __Vdly__custom_gated_pid__DOT__valid_pipe = 0U;
        vlSelfRef.custom_gated_pid__DOT__integrator = 0U;
        vlSelfRef.custom_gated_pid__DOT__dac_out_o = 0U;
        vlSelfRef.custom_gated_pid__DOT__p2_p_term_raw = 0ULL;
        vlSelfRef.custom_gated_pid__DOT__p2_i_term_raw = 0ULL;
        vlSelfRef.custom_gated_pid__DOT__p2_d_term_raw = 0ULL;
        __Vdly__custom_gated_pid__DOT__p3_p_term = 0U;
        __Vdly__custom_gated_pid__DOT__p3_i_term = 0U;
        __Vdly__custom_gated_pid__DOT__p3_d_term = 0U;
        __Vdly__custom_gated_pid__DOT__p4_integrator_next = 0U;
        __Vdly__custom_gated_pid__DOT__p5_pid_sum = 0U;
        vlSelfRef.custom_gated_pid__DOT__p1_error = 0U;
        vlSelfRef.custom_gated_pid__DOT__p1_error_diff = 0U;
        vlSelfRef.custom_gated_pid__DOT__prev_error = 0U;
    }
    vlSelfRef.custom_gated_pid__DOT__valid_pipe = __Vdly__custom_gated_pid__DOT__valid_pipe;
    vlSelfRef.custom_gated_pid__DOT__p3_p_term = __Vdly__custom_gated_pid__DOT__p3_p_term;
    vlSelfRef.custom_gated_pid__DOT__p3_i_term = __Vdly__custom_gated_pid__DOT__p3_i_term;
    vlSelfRef.custom_gated_pid__DOT__p3_d_term = __Vdly__custom_gated_pid__DOT__p3_d_term;
    vlSelfRef.custom_gated_pid__DOT__p4_integrator_next 
        = __Vdly__custom_gated_pid__DOT__p4_integrator_next;
    vlSelfRef.custom_gated_pid__DOT__p5_pid_sum = __Vdly__custom_gated_pid__DOT__p5_pid_sum;
    vlSelfRef.dac_out_o = vlSelfRef.custom_gated_pid__DOT__dac_out_o;
    vlSelfRef.custom_gated_pid__DOT__p2_p_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_p_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_i_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_i_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_d_shifted_raw 
        = (0xffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.custom_gated_pid__DOT__p2_d_term_raw, 0xaU));
    vlSelfRef.custom_gated_pid__DOT__p2_p_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_p_shifted_raw);
    vlSelfRef.custom_gated_pid__DOT__p2_i_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_i_shifted_raw);
    vlSelfRef.custom_gated_pid__DOT__p2_d_shifted = (IData)(vlSelfRef.custom_gated_pid__DOT__p2_d_shifted_raw);
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/thomassv99/fpga_projects/pid_control/verlog_files/custom_gated_pid.v", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/thomassv99/fpga_projects/pid_control/verlog_files/custom_gated_pid.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/thomassv99/fpga_projects/pid_control/verlog_files/custom_gated_pid.v", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.new_data_i & 0xfeU)))) {
        Verilated::overWidthError("new_data_i");}
}
#endif  // VL_DEBUG
