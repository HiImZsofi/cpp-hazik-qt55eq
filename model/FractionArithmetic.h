//
// Created by qt55eq on 2026. 03. 12..
//

#ifndef CPPHAZIK_FRACTIONARITHMETIC_H
#define CPPHAZIK_FRACTIONARITHMETIC_H
#include "Fraction.h"

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);

#endif //CPPHAZIK_FRACTIONARITHMETIC_H