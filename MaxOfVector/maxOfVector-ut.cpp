#include "gtest/gtest.h"
#include "maxOfVector.hpp"

using testPair = std::pair<std::vector<int>, int>;
struct maxOfVectorFixture : public testing::TestWithParam<testPair> {};

TEST_P(maxOfVectorFixture, GivenAVectorShouldReturnMaximumValueInsideThisVector) {
    //GIVEN
    auto [inputVector, expectedResult] = GetParam();
    //WHEN
    auto result = maxOfVector(inputVector);
    //THEN
    EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(maxOfVectorTest,
                        maxOfVectorFixture,
                        testing::Values(
                            testPair{{1, 2, 11, 5, 6, 8, 10}, {11}},
                            testPair{{}, 0},
                            testPair{{0}, {0}},
                            testPair{{-4, -5, -8, -31, -4}, {-4}},
                            testPair{{2, 2, 2, 2, 2, 2, 2}, {2}},
                            testPair{{-5, 3, -7, 2,-8, 3}, {3}},
                            testPair{{10012, 120201, 12020}, {120201}},
                            testPair{{1, 1, 2, 2, 3, 3, -4}, {3}},
                            testPair{{1, 2, 3, 4, 5, 6, 7}, {7}},
                            testPair{{121, 1, 2, 3, 4, 5, 6}, {121}},
                            testPair{{69, 420, 2137, 1337}, {2137}},
                            testPair{{0, 1, 0, 1, 2,  -1, 0, 1}, {2}},
                            testPair{{8, 8, 8, 8, 9, 9, 9, 10, 8}, {10}}));
