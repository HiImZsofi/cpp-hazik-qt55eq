//
// Created by qt55eq on 2026. 03. 12..
//

#include "FractionArithmetic.h"

Fraction operator+(Fraction a, const Fraction &b) {
    return a += b;
}

Fraction operator-(Fraction a, const Fraction &b) {
    return a -= b;
}

Fraction operator*(Fraction a, const Fraction &b) {
    return a *= b;
}

Fraction operator/(Fraction a, const Fraction &b) {
    return a /= b;
}
