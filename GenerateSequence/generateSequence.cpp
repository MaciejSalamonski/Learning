#include "generateSequence.hpp"

constexpr int minSizeOfSequence = 0;

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequenceVector{};

    if (count <= minSizeOfSequence) {
        return sequenceVector;
    }

    sequenceVector.reserve(count);
    for (int i = 1; i <= count; i++) {
        sequenceVector.emplace_back(step * i);
    }

    return sequenceVector;
}
