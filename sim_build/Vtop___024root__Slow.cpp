// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr SData/*15:0*/ Vtop___024root::custom_gated_pid__DOT__MAX_OUT;
constexpr SData/*15:0*/ Vtop___024root::custom_gated_pid__DOT__MIN_OUT;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__COEFF_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__OUT_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__SHIFT_VAL;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__MAX_INT;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__MIN_INT;
constexpr IData/*31:0*/ Vtop___024root::custom_gated_pid__DOT__PAD_OUT;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
