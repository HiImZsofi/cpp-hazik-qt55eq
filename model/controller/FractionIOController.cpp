//
// Created by qt55eq on 2026. 03. 12..
//

#include "FractionIOController.h"

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    os << static_cast<std::string>(f);
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f) {
    int num, denom = 1;
    is >> num;
    if (is.peek() == '/') {
        char slash;
        is >> slash >> denom;
    }
    f = Fraction(num, denom);
    return is;
}
