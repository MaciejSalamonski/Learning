#pragma once

#include <stdint.h>
#include <string>

class Cargo {
protected:
    size_t amount_{};
    std::string name_{};
    size_t basePrice_{};

public:
    Cargo() = default;
    Cargo(size_t amount, const std::string& name, size_t basePrice);
    virtual ~Cargo() = default;
    //virtual void Print() const = 0;
    virtual size_t GetPrice() const = 0;
    virtual std::string GetName() const = 0;
    virtual size_t GetAmount() const = 0;
    virtual size_t GetBasePrice() const = 0;
    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;
    virtual bool operator==(const Cargo& cargo) const = 0;
};
