//
// Created by qt55eq on 2026. 03. 12..
//

#ifndef CPPHAZIK_FRACTIONIOCONTROLLER_H
#define CPPHAZIK_FRACTIONIOCONTROLLER_H
#include <iostream>

#include "../Fraction.h"

std::ostream &operator<<(std::ostream &os, const Fraction &f);

std::istream &operator>>(std::istream &is, Fraction &f);

#endif //CPPHAZIK_FRACTIONIOCONTROLLER_H
