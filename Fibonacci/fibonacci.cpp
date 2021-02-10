#include "fibonacci.hpp"

constexpr int sequenceMustBeGrOrEqThanZero = 0;

int fibonacci_iterative(int sequence) {
    if (sequence < sequenceMustBeGrOrEqThanZero) {
        return 0;
    }
    if (sequence == 0 || sequence == 1) {
        return sequence;
    }

    int fibBeforePrevious{};
    int fibPrevious{1};
    int result{};

    for (int i = 2; i <= sequence; i++) {
        result = fibPrevious + fibBeforePrevious;
        fibBeforePrevious = fibPrevious;
        fibPrevious = result;
    }

    return fibPrevious;
}

int fibonacci_recursive(int sequence) {
    if (sequence < sequenceMustBeGrOrEqThanZero) {
        return 0;
    }

    return (sequence == 0 || sequence == 1) ? sequence : fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
