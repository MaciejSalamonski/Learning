#include "validation.hpp"

#include <algorithm>
#include <cctype>

constexpr int minimumPasswordLength = 9;

std::string getErrorMessage(const ErrorCode& errorCode) {
    switch(errorCode) {
        case ErrorCode::Ok:
            return "Ok";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least nine characters!";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number!";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character!";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one uppercase letter!";
            break;
        case ErrorCode::PasswordDoesNotMatch:
            return "Password does not match!";
        default:
            return "Unknown error!";
    }
}

bool doesPasswordMatch(const std::string& firstPassword, const std::string& secondPassword) {
    return firstPassword == secondPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if(password.length() < minimumPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if(std::none_of(std::cbegin(password), std::cend(password), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if(std::none_of(std::cbegin(password), std::cend(password), ::ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if(std::none_of(std::cbegin(password), std::cend(password), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword) {
    if(!doesPasswordMatch(firstPassword, secondPassword)) {
      return ErrorCode::PasswordDoesNotMatch;  
    }

    return checkPasswordRules(firstPassword);
}
