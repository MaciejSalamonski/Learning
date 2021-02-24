#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
protected:
    size_t percentage_{};

public:
    Alcohol() = default;
    Alcohol(size_t amount, const std::string& name, size_t basePrice, size_t percentage);
    ~Alcohol() override = default;
    //void Print() const override;
    std::string GetName() const override { return name_; }
    size_t GetAmount() const override { return amount_; }
    size_t GetBasePrice() const override { return basePrice_; }
    size_t GetPercentage() const { return percentage_; }
    size_t GetPrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    //void NextDay() override;
};