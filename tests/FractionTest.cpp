//
// Created by qt55eq on 2026. 03. 12..
//

#include <gtest/gtest.h>
#include "../model/Fraction.h"
#include "../model/arithmetics/FractionArithmetic.h"

TEST(FractionTest, ConstructorReduces) {
    const Fraction f(4,8);
    EXPECT_EQ(f.getNumerator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST(FractionTest, Addition) {
    const Fraction result = Fraction(1, 4) + Fraction(1, 4);
    EXPECT_EQ(result, Fraction(1, 2));
}

TEST(FractionTest, Comparison) {
    EXPECT_TRUE(Fraction(1, 3) < Fraction(1, 2));
    EXPECT_FALSE(Fraction(1, 2) < Fraction(1, 3));
}

TEST(FractionTest, ParseString) {
    const Fraction f = Fraction::parse("3/4");
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 4);
}