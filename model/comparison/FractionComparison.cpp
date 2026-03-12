//
// Created by qt55eq on 2026. 03. 12..
//

#include "FractionComparison.h"

bool operator==(const Fraction &a, const Fraction &b) {
    return a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator();
}

bool operator!=(const Fraction &a, const Fraction &b) {
    return !(a == b);
}

bool operator<(const Fraction &a, const Fraction &b) {
    return a.getNumerator() * b.getDenominator() < b.getNumerator() * a.getDenominator();
}

bool operator>(const Fraction &a, const Fraction &b) {
    return b < a;
}

bool operator<=(const Fraction &a, const Fraction &b) {
    return !(a > b);
}

bool operator>=(const Fraction &a, const Fraction &b) {
    return !(a < b);
}
