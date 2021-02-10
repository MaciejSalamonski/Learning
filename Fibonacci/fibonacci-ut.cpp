#include "fibonacci.hpp"
#include "gtest/gtest.h"

using testPair = std::pair<int, int>;
struct fibonacciTestFixture : public testing::TestWithParam<testPair> {};

TEST_P(fibonacciTestFixture, GivenAnInputNumberOfSequenceShouldCalculateFibonacciNumberIteratively) {
    //GIVEN
    auto [inputSequence, expectedResult] = GetParam();
    //WHEN
    auto resultOfCalculations = fibonacci_iterative(inputSequence); 
    //THEN
    EXPECT_EQ(resultOfCalculations, expectedResult);
}

TEST_P(fibonacciTestFixture, GivenAnInputNumberOfSequenceShouldCalculateFibonacciNumberRecursively) {
    //GIVEN
    auto [inputSequence, expectedResult] = GetParam();
    //WHEN
    auto resultOfCalculations = fibonacci_recursive(inputSequence); 
    //THEN
    EXPECT_EQ(resultOfCalculations, expectedResult);
}

INSTANTIATE_TEST_CASE_P(FibonacciCounting,
                        fibonacciTestFixture,
                        testing::Values(
                            testPair{5, 5},
                            testPair{10, 55},
                            testPair{0, 0},
                            testPair{1, 1},
                            testPair{7, 13},
                            testPair{8, 21},
                            testPair{10, 55},
                            testPair{9, 34},
                            testPair{11, 89},
                            testPair{-20, 0},
                            testPair{15, 610},
                            testPair{16, 987},
                            testPair{18, 2584},
                            testPair{40, 102334155},
                            testPair{32, 2178309}));
