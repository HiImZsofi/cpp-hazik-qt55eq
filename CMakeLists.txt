cmake_minimum_required(VERSION 4.1)
project(cpphazik)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpphazik main.cpp
        model/Fraction.cpp
        model/Fraction.h
        model/Fraction.cpp
        model/FractionArithmetic.cpp
        model/FractionArithmetic.cpp
        model/FractionArithmetic.h
        model/FractionComparison.cpp
        model/FractionComparison.h)
