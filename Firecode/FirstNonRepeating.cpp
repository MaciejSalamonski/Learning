#include <algorithm>
#include <string>
#include <iostream>

char first_non_repeating(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        auto num = std::count_if(str.cbegin(), str.cend(),
                                    [&str, &i](char character){
                                        return str[i] == character;
                                    });
        if(num == 1) {
            return str[i]; 
        }
        continue;
    }

    return '0';
}

int main() {
    std::string str{"cdcd"};
    char character = first_non_repeating(str);
    std::cout << character << '\n';

    return 0;
}
