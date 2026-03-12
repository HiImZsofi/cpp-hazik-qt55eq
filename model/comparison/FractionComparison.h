//
// Created by qt55eq on 2026. 03. 12..
//

#ifndef CPPHAZIK_FRACTIONCOMPARISON_H
#define CPPHAZIK_FRACTIONCOMPARISON_H
#include "../Fraction.h"

bool operator==(const Fraction& a, const Fraction& b);
bool operator!=(const Fraction& a, const Fraction& b);
bool operator<(const Fraction& a, const Fraction& b);
bool operator>(const Fraction& a, const Fraction& b);
bool operator<=(const Fraction& a, const Fraction& b);
bool operator>=(const Fraction& a, const Fraction& b);

#endif //CPPHAZIK_FRACTIONCOMPARISON_H