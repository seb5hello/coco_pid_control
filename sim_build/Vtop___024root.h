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
    VL_IN8(rst,0,0);
    CData/*0:0*/ pid_controller__DOT__clk;
    CData/*0:0*/ pid_controller__DOT__rst;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(setpoint,15,0);
    VL_IN16(feedback,15,0);
    VL_IN16(kp,15,0);
    VL_IN16(ki,15,0);
    VL_IN16(kd,15,0);
    VL_OUT16(control_out,15,0);
    SData/*15:0*/ pid_controller__DOT__setpoint;
    SData/*15:0*/ pid_controller__DOT__feedback;
    SData/*15:0*/ pid_controller__DOT__kp;
    SData/*15:0*/ pid_controller__DOT__ki;
    SData/*15:0*/ pid_controller__DOT__kd;
    SData/*15:0*/ pid_controller__DOT__control_out;
    SData/*15:0*/ pid_controller__DOT__error;
    SData/*15:0*/ pid_controller__DOT__integral;
    SData/*15:0*/ pid_controller__DOT__last_error;
    SData/*15:0*/ pid_controller__DOT__derivative;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
