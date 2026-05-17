// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/thomassv99/fpga_projects/pid_control/verlog_files/custom_gated_pid.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->new_data_i = VL_RAND_RESET_I(1);
    vlSelf->scan_start_target_i = VL_RAND_RESET_I(32);
    vlSelf->reg_master_peak_1_i = VL_RAND_RESET_I(32);
    vlSelf->kp_i = VL_RAND_RESET_I(16);
    vlSelf->ki_i = VL_RAND_RESET_I(16);
    vlSelf->kd_i = VL_RAND_RESET_I(16);
    vlSelf->dac_out_o = VL_RAND_RESET_I(16);
    vlSelf->custom_gated_pid__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->custom_gated_pid__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->custom_gated_pid__DOT__new_data_i = VL_RAND_RESET_I(1);
    vlSelf->custom_gated_pid__DOT__scan_start_target_i = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__reg_master_peak_1_i = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__kp_i = VL_RAND_RESET_I(16);
    vlSelf->custom_gated_pid__DOT__ki_i = VL_RAND_RESET_I(16);
    vlSelf->custom_gated_pid__DOT__kd_i = VL_RAND_RESET_I(16);
    vlSelf->custom_gated_pid__DOT__dac_out_o = VL_RAND_RESET_I(16);
    vlSelf->custom_gated_pid__DOT__prev_error = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__integrator = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__valid_pipe = VL_RAND_RESET_I(5);
    vlSelf->custom_gated_pid__DOT__p1_error = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p1_error_diff = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p2_p_term_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_i_term_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_d_term_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_p_shifted_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_i_shifted_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_d_shifted_raw = VL_RAND_RESET_Q(48);
    vlSelf->custom_gated_pid__DOT__p2_p_shifted = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p2_i_shifted = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p2_d_shifted = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p3_p_term = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p3_i_term = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p3_d_term = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p4_integrator_next = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__p5_pid_sum = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator = VL_RAND_RESET_Q(33);
    vlSelf->custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term = VL_RAND_RESET_Q(33);
    vlSelf->custom_gated_pid__DOT__unnamedblk1__DOT__temp_int = VL_RAND_RESET_Q(33);
    vlSelf->custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int = VL_RAND_RESET_Q(33);
    vlSelf->custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int = VL_RAND_RESET_Q(33);
    vlSelf->custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out = VL_RAND_RESET_I(32);
    vlSelf->custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
