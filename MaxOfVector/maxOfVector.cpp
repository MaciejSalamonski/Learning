#include "maxOfVector.hpp"

#include <algorithm>

int maxOfVector(const std::vector<int>& vectorWithNumbers) {
    if (vectorWithNumbers.empty()) {
        return 0;
    }

    return *(std::max_element(std::begin(vectorWithNumbers), std::end(vectorWithNumbers)));
}
