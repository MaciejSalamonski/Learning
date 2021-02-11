#include "addEven.hpp"
#include "gtest/gtest.h"

using testPair = std::pair<std::vector<int>, int>;
struct addEvenTestFixture : public testing::TestWithParam<testPair> {};

TEST_P(addEvenTestFixture, GivenAVectorWithNumbersShouldReturnAResultOfAddingOnlyEvenNumbers) {
    //GIVEN
    auto [inputVector, expectedResult] = GetParam();
    //WHEN
    auto result = addEven(inputVector);
    //THEN
    EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(AddingEvenNumbers,
                        addEvenTestFixture, 
                        testing::Values(
                            testPair{{1, 2, 3, 4, 5}, {6}},
                            testPair{{2, 3, 5, 7, 9, 10, 12}, {24}},
                            testPair{{5, 5, 5, 5, 5, 5, 5, 5, 5,}, {0}},
                            testPair{{0, 0, 0}, {0}},
                            testPair{{2, 2, 2, 2, 2, 2, 2}, {14}},
                            testPair{{-4, 3, -2, 5, -3, 4, 6, -2}, {2}},
                            testPair{{}, {0}},
                            testPair{{1}, {0}},
                            testPair{{4}, {4}}));

