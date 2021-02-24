#pragma once

#include "Cargo.hpp"

enum class Rarity {
    Low = 0,
    Medium = 5,
    Rare = 12,
    VeryRare = 25,
};

class Item : public Cargo {
protected:
    Rarity rarity_{};
    size_t percentage_{};

public:
    Item() = default;
    Item(size_t amount, const std::string& name, size_t basePrice, Rarity rarity);
    ~Item() override = default;
    //void Print() const override;
    std::string GetName() const override { return name_; }
    size_t GetAmount() const override { return amount_; }
    size_t GetBasePrice() const override { return basePrice_; }
    Rarity GetRarity() const { return rarity_; }
    size_t GetPrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    //void NextDay() override;
};