#include <algorithm>
#include <iostream>
#include <string>

bool permutation(std::string firstString, std::string secondString) {
    return std::is_permutation(firstString.cbegin(), firstString.cend(), secondString.cbegin());
}

int main() {
    std::string firstString = "CAT";
    std::string secondString = "ACT";
    bool result = permutation(firstString, secondString); 
    std::cout << result << '\n';

    return 0;
}
