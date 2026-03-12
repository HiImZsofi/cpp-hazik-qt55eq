//
// Created by qt55eq on 2026. 03. 11..
//

#include "Fraction.h"
#include "arithmetics/FractionArithmetic.h"

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

Fraction::Fraction(const Fraction &other) : numerator(other.numerator), denominator(other.denominator) {
} //todo mi ez az issue

Fraction &Fraction::operator+=(const Fraction &other) {
    *this = *this + other;
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    *this = *this - other;
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    *this = *this * other;
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    *this = *this / other;
    return *this;
}

Fraction::operator int() const {
    return numerator / denominator;
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

Fraction::operator bool() const {
    return numerator != 0;
}

Fraction::operator std::string() const {
    if (denominator == 1) {
        return std::to_string(numerator);
    }

    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

/**
 * std::string::npos -> / not found (tort egesz szam)
 * std::stoi -> string to int
 *
 * @param str
 */
Fraction::Fraction(const std::string &str) {
    const size_t slash = str.find('/');
    if (slash == std::string::npos) {
        numerator = std::stoi(str);
        denominator = 1;
    } else {
        numerator = std::stoi(str.substr(0, slash));
        denominator = std::stoi(str.substr(slash + 1));
    }

    if (denominator == 0) {
        throw std::invalid_argument("A nevező nem lehet nulla");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    const int gcd = std::gcd(std::abs(numerator), denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}