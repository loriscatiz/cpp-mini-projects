#include <string>

#include "Animal.hpp"

#pragma once

class Cat : public Animal {
   public:
    Cat(const std::string& name);

    void speak() const override;
    void info() const override;
};
