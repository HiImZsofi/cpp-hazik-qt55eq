//
// Created by qt55eq on 2026. 03. 11..
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

Fraction::Fraction(const int wholeNum) : numerator(wholeNum), denominator(1) {
}

Fraction::Fraction(const double decimal) {
    constexpr int precision = 1000000;
    const int nom = static_cast<int>(decimal * precision);
    constexpr int denom = precision;
    const int gcd = std::gcd(std::abs(nom), denom);

    this->numerator = nom / gcd;
    this->denominator = denom / gcd;
}

Fraction::Fraction(const Fraction &other) : numerator(other.numerator), denominator(other.denominator) {} //todo mi ez az issue

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}
