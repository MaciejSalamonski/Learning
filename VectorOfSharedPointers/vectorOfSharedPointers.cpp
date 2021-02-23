#include "vectorOfSharedPointers.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vectorWithSharedPtrs{};

    for (int i = 0; i < count; i++) {
        vectorWithSharedPtrs.emplace_back(std::make_shared<int>(i));
    }

    return vectorWithSharedPtrs;
}

void print(const std::vector<std::shared_ptr<int>>& vectorWithSharedPtrs) {
    for (const auto& el : vectorWithSharedPtrs) {
        std::cout << *el << " ";
    }
}

void add10(std::vector<std::shared_ptr<int>>& vectorWithSharedPtrs) {
    for (auto& el : vectorWithSharedPtrs) {
        *el += 10;
    }
}

void sub10(int* const ptr) {
    *ptr -= 10;
}

void sub10(std::vector<std::shared_ptr<int>>& vectorWithSharedPtrs) {
    for (auto& el : vectorWithSharedPtrs) {
        sub10(el.get());
    }
}


