#include "addEven.hpp"

constexpr int evenNumber = 2;

int addEven(const std::vector<int>& numbers) {
    int result{};

    for (const auto& el : numbers) {
        if(el % evenNumber == 0) {
            result += el;
        }
    }

    return result;
}
