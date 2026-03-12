//
// Created by qt55eq on 2026. 03. 12..
//

#include "FractionArithmetic.h"

Fraction operator+(const Fraction &a, const Fraction &b) {
    return {
        a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator(),
        a.getDenominator() * b.getDenominator()
    };
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    return {
        a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator(),
        a.getDenominator() * b.getDenominator()
    };
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    return {
        a.getNumerator() * b.getNumerator(),
        a.getDenominator() * b.getDenominator()
    };
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    return {
        a.getNumerator() * b.getDenominator(),
        a.getDenominator() * b.getNumerator()
    };
}
