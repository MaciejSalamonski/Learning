#pragma once

#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordDoesNotMatch
};

std::string getErrorMessage(const ErrorCode& errorCode);
bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword);


