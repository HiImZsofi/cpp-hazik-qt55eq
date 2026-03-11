//
// Created by zsofi on 2026. 03. 11..
//

#include "Fraction.h"

#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("A nevező nem lehet nulla");
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    const int gcd = std::gcd(std::abs(numerator), denominator);
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}
