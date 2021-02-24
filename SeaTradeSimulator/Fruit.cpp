#include "Fruit.hpp"

Fruit::Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expiryDate)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate) {}

Fruit::Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expiryDate, size_t timeElapsed)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate), timeElapsed_(timeElapsed) {}

//Override from Cargo

size_t Fruit::GetPrice() const {
    return basePrice_ * static_cast<size_t>((expiryDate_ - timeElapsed_) / expiryDate_);
}

Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;

    return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
    if (amount_ < amount) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;

    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (typeid(cargo) != typeid(*this)) {
        return false;
    }

    auto fruit = static_cast<const Fruit&>(cargo);
    return (amount_ == fruit.GetAmount()) && (name_ == fruit.GetName()) && (basePrice_ == fruit.GetBasePrice());
}
