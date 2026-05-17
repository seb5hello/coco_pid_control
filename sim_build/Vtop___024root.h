// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(new_data_i,0,0);
    CData/*0:0*/ custom_gated_pid__DOT__clk;
    CData/*0:0*/ custom_gated_pid__DOT__rst_n;
    CData/*0:0*/ custom_gated_pid__DOT__new_data_i;
    CData/*4:0*/ custom_gated_pid__DOT__valid_pipe;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(kp_i,15,0);
    VL_IN16(ki_i,15,0);
    VL_IN16(kd_i,15,0);
    VL_OUT16(dac_out_o,15,0);
    SData/*15:0*/ custom_gated_pid__DOT__kp_i;
    SData/*15:0*/ custom_gated_pid__DOT__ki_i;
    SData/*15:0*/ custom_gated_pid__DOT__kd_i;
    SData/*15:0*/ custom_gated_pid__DOT__dac_out_o;
    VL_IN(scan_start_target_i,31,0);
    VL_IN(reg_master_peak_1_i,31,0);
    IData/*31:0*/ custom_gated_pid__DOT__scan_start_target_i;
    IData/*31:0*/ custom_gated_pid__DOT__reg_master_peak_1_i;
    IData/*31:0*/ custom_gated_pid__DOT__prev_error;
    IData/*31:0*/ custom_gated_pid__DOT__integrator;
    IData/*31:0*/ custom_gated_pid__DOT__p1_error;
    IData/*31:0*/ custom_gated_pid__DOT__p1_error_diff;
    IData/*31:0*/ custom_gated_pid__DOT__p2_p_shifted;
    IData/*31:0*/ custom_gated_pid__DOT__p2_i_shifted;
    IData/*31:0*/ custom_gated_pid__DOT__p2_d_shifted;
    IData/*31:0*/ custom_gated_pid__DOT__p3_p_term;
    IData/*31:0*/ custom_gated_pid__DOT__p3_i_term;
    IData/*31:0*/ custom_gated_pid__DOT__p3_d_term;
    IData/*31:0*/ custom_gated_pid__DOT__p4_integrator_next;
    IData/*31:0*/ custom_gated_pid__DOT__p5_pid_sum;
    IData/*31:0*/ custom_gated_pid__DOT__unnamedblk2__DOT__ext_max_out;
    IData/*31:0*/ custom_gated_pid__DOT__unnamedblk2__DOT__ext_min_out;
    IData/*31:0*/ __VactIterCount;
    QData/*47:0*/ custom_gated_pid__DOT__p2_p_term_raw;
    QData/*47:0*/ custom_gated_pid__DOT__p2_i_term_raw;
    QData/*47:0*/ custom_gated_pid__DOT__p2_d_term_raw;
    QData/*47:0*/ custom_gated_pid__DOT__p2_p_shifted_raw;
    QData/*47:0*/ custom_gated_pid__DOT__p2_i_shifted_raw;
    QData/*47:0*/ custom_gated_pid__DOT__p2_d_shifted_raw;
    QData/*32:0*/ custom_gated_pid__DOT__unnamedblk1__DOT__ext_integrator;
    QData/*32:0*/ custom_gated_pid__DOT__unnamedblk1__DOT__ext_p3_i_term;
    QData/*32:0*/ custom_gated_pid__DOT__unnamedblk1__DOT__temp_int;
    QData/*32:0*/ custom_gated_pid__DOT__unnamedblk1__DOT__ext_max_int;
    QData/*32:0*/ custom_gated_pid__DOT__unnamedblk1__DOT__ext_min_int;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr SData/*15:0*/ custom_gated_pid__DOT__MAX_OUT = 0x7fffU;
    static constexpr SData/*15:0*/ custom_gated_pid__DOT__MIN_OUT = 0x8000U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__COEFF_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__OUT_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__SHIFT_VAL = 0x0000000aU;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__MAX_INT = 0x0007a120U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__MIN_INT = 0xfff85ee0U;
    static constexpr IData/*31:0*/ custom_gated_pid__DOT__PAD_OUT = 0x00000010U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
