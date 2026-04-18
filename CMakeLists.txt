cmake_minimum_required(VERSION 3.28)
project(cpphazik)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpphazik main.cpp
        model/Fraction.cpp
        model/arithmetics/FractionArithmetic.cpp
        model/controller/FractionIOController.cpp
        model/KeyNotFoundException.h)

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
        model/controller/FractionIOController.cpp
)
target_link_libraries(cpphazik_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(cpphazik_tests)
