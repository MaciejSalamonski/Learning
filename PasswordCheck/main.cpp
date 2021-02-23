#include "validation.hpp"

#include <iostream>

int main() {
    std::string password;
    std::string repeatedPassword;

    std::cout << "Set new Password: ";
    std::cin >> password;
    std::cout << "Repeated password: ";
    std::cin >> repeatedPassword;
    auto result = checkPassword(password, repeatedPassword);
    std::cout << getErrorMessage(result) << '\n';

    return 0;
}
