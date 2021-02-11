#include "gtest/gtest.h"
#include "nwdNww.hpp"

using testTuple = std::tuple<std::pair<int, int>, int>;
struct nwdTestFixture : public testing::TestWithParam<testTuple> {};

TEST_P(nwdTestFixture, GivenAnInputNumbersShouldReturnNWD) {
    //GIVEN
    auto [inputNumbers, expectedResult] = GetParam();
    //WHEN
    auto result = NWD(inputNumbers.first, inputNumbers.second);
    //THEN
    EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(nwdTest,
                        nwdTestFixture,
                        testing::Values(
                            testTuple{{255, 15}, {15}},
                            testTuple{{10, 10}, {10}},
                            testTuple{{44, 123}, {1}},
                            testTuple{{123, 44}, {1}},
                            testTuple{{891, 33}, {33}},
                            testTuple{{23122, 322}, {2}},
                            testTuple{{4345, 25}, {5}},
                            testTuple{{65464, 344324}, {4}},
                            testTuple{{2, 2}, {2}},
                            testTuple{{1, 1}, {1}},
                            testTuple{{1, 0}, {1}},
                            testTuple{{0, 1}, {1}},
                            testTuple{{0, 10}, {10}},
                            testTuple{{0, 0}, {0}},
                            testTuple{{-10, -2}, {2}},
                            testTuple{{10, 2}, {2}},
                            testTuple{{10, -2}, {2}}));

struct nwwTestFixture : public testing::TestWithParam<testTuple> {};

TEST_P(nwwTestFixture, GivenAnInputNumbersShouldReturnNWW) {
    //GIVEN
    auto [inputNumbers, expectedResult] = GetParam();
    //WHEN
    auto result = NWW(inputNumbers.first, inputNumbers.second);
    //THEN
    EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(nwwTest,
                        nwwTestFixture,
                        testing::Values(
                            testTuple{{255, 15}, {255}},
                            testTuple{{24, 36}, {72}},
                            testTuple{{50, 17}, {850}},
                            testTuple{{50, 30}, {150}},
                            testTuple{{23122, 322}, {3722642}},
                            testTuple{{28, 14}, {28}},
                            testTuple{{105, 25}, {525}},
                            testTuple{{0, 0}, {0}},
                            testTuple{{1, 0}, {0}},
                            testTuple{{0, 1}, {0}},
                            testTuple{{0, -2}, {0}},
                            testTuple{{1, 1}, {1}},
                            testTuple{{-1, 1}, {1}},
                            testTuple{{1, -1}, {1}},
                            testTuple{{-1, -1}, {1}},
                            testTuple{{-10, -10}, {10}},
                            testTuple{{-10, -2}, {10}}));

