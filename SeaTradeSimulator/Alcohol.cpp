#include "Alcohol.hpp"

constexpr size_t maxAlcoholPower = 96;

Alcohol::Alcohol(size_t amount, const std::string& name, size_t basePrice, size_t percentage)
    : Cargo(amount, name, basePrice), percentage_(percentage) {}

size_t Alcohol::GetPrice() const {
    return basePrice_ * static_cast<int>(percentage_ / maxAlcoholPower);
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;

    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    if (amount_ < amount) {
        amount_ = 0;

        return *this;
    }
    amount_ -= amount;

    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(cargo) != typeid(*this)) {
        return false;
    }
    auto alcohol = static_cast<const Alcohol&>(cargo);

    return (amount_ == alcohol.GetAmount()) && (name_ == alcohol.GetName()) && (basePrice_ == alcohol.GetBasePrice()) && (percentage_ == alcohol.GetPercentage());
}