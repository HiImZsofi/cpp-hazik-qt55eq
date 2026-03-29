//
// Created by qt55eq on 2026. 03. 12..
//

#include "FractionIOController.h"

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    if (f.getDenominator() == 1) {
        os << f.getNumerator();
    } else {
        os << f.getNumerator() << "/" << f.getDenominator();
    }

    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f) {
    int num, denom = 1;
    is >> num;
    if (is.peek() == '/') {
        char slash;
        is >> slash >> denom;
    }
    f = {num, denom};
    return is;
}
