#include "generateSequence.hpp"
#include "gtest/gtest.h"

using testTuple = std::tuple<std::pair<int, int>, std::vector<int>>;
struct generateSequenceFixture : public testing::TestWithParam<testTuple> {};

TEST_P(generateSequenceFixture, GivenBothCountAndAStepNumbersShouldReturnVectorWithSequence) {
    //GIVEN
    auto [inputNumber, expectedResult] = GetParam();
    //WHEN
    auto result = generateSequence(inputNumber.first, inputNumber.second);
    //THEN
    EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(generateSequenceTest,
                        generateSequenceFixture,
                        testing::Values(
                            testTuple{{5, 3}, {3, 6, 9, 12, 15}},
                            testTuple{{10, 1}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
                            testTuple{{-4, 2}, {}},
                            testTuple{{5, -2}, {-2, -4, -6, -8, -10}},
                            testTuple{{3, 4}, {4, 8, 12}},
                            testTuple{{0, 1}, {}},
                            testTuple{{4, 0}, {0, 0, 0, 0}},
                            testTuple{{0, 0}, {}},
                            testTuple{{-10, -1}, {}}));
