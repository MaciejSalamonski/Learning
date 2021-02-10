#include <iostream>

#include "calculate.hpp"

constexpr int doNotDivideByZero = 0;

std::string calculate(const std::string& command, int first, int second) {
    if(command == "add") {
        return std::to_string(first + second);
    }
    if(command == "subtract") {
        return std::to_string(first - second);
    }
    if(command == "multiply") {
        return std::to_string(first * second);
    }
    if(command == "divide") {
        return (second != doNotDivideByZero) ? std::to_string(first / second) : "You can't divide by zero!";
    }

    return "Wrong command!";
}
