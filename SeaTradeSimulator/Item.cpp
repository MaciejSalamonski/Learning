#include "Item.hpp"

Item::Item(size_t amount, const std::string& name, size_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

size_t Item::GetPrice() const {
    return basePrice_ * static_cast<size_t>(rarity_);
}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;

    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount_ < amount) {
        amount_ = 0;

        return *this;
    }
    amount_ -= amount;

    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) != typeid(*this)) {
        return false;
    }
    auto item = static_cast<const Item&>(cargo);

    return (amount_ == item.GetAmount()) && (name_ == item.GetName()) && (basePrice_ == item.GetBasePrice()) && (rarity_ == item.GetRarity());
}
