#include "addEven.hpp"

#include <iostream>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto result = addEven(vec);

    std::cout << result << '\n';

    return 0;
}
