cmake_minimum_required(VERSION 4.1)
project(cpphazik)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpphazik main.cpp
        model/Fraction.cpp
        model/Fraction.h
        model/Fraction.cpp
        model/arithmetics/FractionArithmetic.cpp
        model/arithmetics/FractionArithmetic.cpp
        model/arithmetics/FractionArithmetic.h
        model/comparison/FractionComparison.cpp
        model/comparison/FractionComparison.h
        model/controller/FractionIOController.cpp
        model/controller/FractionIOController.h)
