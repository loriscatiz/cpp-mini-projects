#include <string>

#include "Animal.hpp"

#pragma once

class Dog : public Animal {
   public:
    Dog(const std::string& name);

    void speak() const override;
    void info() const override;
};
