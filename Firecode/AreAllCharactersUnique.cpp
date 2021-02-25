#include <algorithm>
#include <string>
#include <iostream>

bool are_all_characters_unique(std::string str) {
    std::sort(str.begin(), str.end());
    auto it = std::unique(str.begin(), str.end());
    
    return it == str.end();
}
    
int main() {
    std::string sth{};
    std::cin >> sth;
    std::cout << are_all_characters_unique(sth) << '\n';

    return 0;
}
