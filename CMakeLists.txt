cmake_minimum_required(VERSION 4.1)
project(cpphazik)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpphazik main.cpp
        model/Fraction.cpp
        model/Fraction.h
        model/Fraction.cpp
        model/arithmetics/FractionArithmetic.cpp
        model/arithmetics/FractionArithmetic.h
        model/comparison/FractionComparison.cpp
        model/comparison/FractionComparison.h
        model/controller/FractionIOController.cpp
        model/controller/FractionIOController.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(cpphazik_tests
        tests/FractionTest.cpp
        model/Fraction.cpp
        model/arithmetics/FractionArithmetic.cpp
        model/comparison/FractionComparison.cpp
        model/controller/FractionIOController.cpp
)
target_link_libraries(cpphazik_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(cpphazik_tests)
