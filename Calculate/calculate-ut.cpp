#include "calculate.hpp"
#include "gtest/gtest.h"

using testTuple = std::tuple<std::string, std::pair<int, int>, std::string>;
struct CalculateTestFixture : public testing::TestWithParam<testTuple> {};

TEST_P(CalculateTestFixture, GivenAnComanndAndPairOfNumbersShouldReturnExpectedResult) {
    //GIVEN
    auto [inputCommand, pairOfNumbers, expectedResult] = GetParam();
    //WHEN
    auto calculationsResult = calculate(inputCommand, pairOfNumbers.first, pairOfNumbers.second);
    //THEN
    EXPECT_EQ(calculationsResult, expectedResult);
}

INSTANTIATE_TEST_CASE_P(SomeCalculations,
                        CalculateTestFixture,
                        testing::Values(
                            testTuple{{"add"}, {10, 20}, {"30"}},
                            testTuple{{"add"}, {25, 52}, {"77"}},
                            testTuple{{"multiply"}, {5, 5}, {"25"}},
                            testTuple{{"multiply"}, {20, 10}, {"200"}},
                            testTuple{{"subtract"}, {20, 10}, {"10"}},
                            testTuple{{"subtract"}, {-50, -20}, {"-30"}},
                            testTuple{{"divide"}, {4, 2}, {"2"}},
                            testTuple{{"divide"}, {100, 20}, {"5"}},
                            testTuple{{"divide"}, {10, 0}, {"You can't divide by zero!"}},
                            testTuple{{"sdfdf"}, {20, 50}, {"Wrong command!"}}));
