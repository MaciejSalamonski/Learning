#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
    size_t expiryDate_{};
    size_t timeElapsed_{};

public:
    Fruit() = default;
    Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expiryDate);
    Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expiryDate, size_t timeElapsed);
    Fruit(size_t amount, const Fruit* fruit);
    ~Fruit() override = default;
    //void Print() const override;
    size_t GetPrice() const override;
    std::string GetName() const override { return name_; }
    size_t GetAmount() const override { return amount_; }
    size_t GetBasePrice() const override { return basePrice_; }
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    //void NextDay() override;
    size_t GetTimeElpased() const { return timeElapsed_; }
    size_t GetExpiryDate() const { return expiryDate_; };
};
