//
// Created by zsofi on 2026. 03. 11..
//

#ifndef CPPHAZIK_FRACTION_H
#define CPPHAZIK_FRACTION_H


class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);

    int getNumerator() const;
    int getDenominator() const;
};


#endif //CPPHAZIK_FRACTION_H
