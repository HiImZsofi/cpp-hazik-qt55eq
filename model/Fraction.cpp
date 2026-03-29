//
// Created by qt55eq on 2026. 03. 11..
//

#include "Fraction.h"
#include "arithmetics/FractionArithmetic.h"

#include <numeric>
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("A nevező nem lehet nulla");
    }

    const int sign = denominator < 0 ? -1 : 1;
    const int gcd = std::gcd(std::abs(numerator), std::abs(denominator));
    this->numerator = sign * numerator / gcd;
    this->denominator = sign * denominator / gcd;
}

Fraction::Fraction(const int wholeNum) : numerator(wholeNum), denominator(1) {
}

Fraction::Fraction(const double decimal) {
    constexpr int precision = 1000000;
    const int nom = static_cast<int>(decimal * precision);
    const int gcd = std::gcd(std::abs(nom), precision);

    this->numerator = nom / gcd;
    this->denominator = precision / gcd;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    *this = Fraction(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    *this = Fraction(
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    );
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    *this = Fraction(
        numerator * other.numerator,
        denominator * other.denominator
    );
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    *this = Fraction(
        numerator * other.denominator,
        denominator * other.numerator
    );
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
Fraction Fraction::parse(const std::string &str) {
    int num, denom;

    if (const size_t slash = str.find('/'); slash == std::string::npos) {
        num = std::stoi(str);
        denom = 1;
    } else {
        num = std::stoi(str.substr(0, slash));
        denom = std::stoi(str.substr(slash + 1));
    }

    return {num, denom};
}

bool Fraction::operator==(const Fraction &other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction &other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction &other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction &other) const {
    return !(*this > other);
}

bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}
