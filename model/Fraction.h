//
// Created by qt55eq on 2026. 03. 11..
//

#ifndef CPPHAZIK_FRACTION_H
#define CPPHAZIK_FRACTION_H
#include <string>


class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(int wholeNum);
    Fraction(double decimal);
    Fraction(const Fraction& other);

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    explicit operator int() const;
    explicit operator double() const;
    explicit operator bool() const;
    explicit operator std::string() const;

    Fraction(const std::string& str);

    [[nodiscard]] int getNumerator() const;
    [[nodiscard]] int getDenominator() const;
};


#endif //CPPHAZIK_FRACTION_H
