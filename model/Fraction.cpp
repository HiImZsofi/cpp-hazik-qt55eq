//
// Created by qt55eq on 2026. 03. 11..
//

#include "Fraction.h"
#include "arithmetics/FractionArithmetic.h"

#include <numeric>
#include <sstream>
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("A nevező nem lehet nulla");
    }

    const int sign = denominator < 0 ? -1 : 1;
    const int gcd = std::gcd(std::abs(numerator), std::abs(denominator));
    this->numerator /= gcd;
    this->numerator *= sign;
    this->denominator /= gcd;
    this->denominator *= sign;
}

Fraction::Fraction(const int wholeNum) : numerator(wholeNum), denominator(1) {
}

Fraction::Fraction(const double decimal)
    : Fraction(static_cast<int>(decimal * 1000000), 1000000) {
}

Fraction &Fraction::operator+=(const Fraction &other) {
    *this = Fraction(numerator * other.denominator + other.numerator * denominator,
                     denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    return *this += Fraction(-other.numerator, other.denominator);
}

Fraction &Fraction::operator*=(const Fraction &other) {
    *this = Fraction(numerator * other.numerator,
                     denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    *this = Fraction(numerator * other.denominator,
                     denominator * other.numerator);
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

Fraction Fraction::parse(const std::string &str) {
    Fraction result(0);
    std::istringstream(str) >> result;
    return result;
}

bool Fraction::operator==(const Fraction &other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction &other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
    return static_cast<double>(*this) < static_cast<double>(other);
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
