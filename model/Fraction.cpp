//
// Created by zsofi on 2026. 03. 11..
//

#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("A nevező nem lehet nulla");
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}
