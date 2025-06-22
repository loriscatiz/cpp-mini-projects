#include <string>

#pragma once

class Animal {
   protected:
    std::string name;

   public:
    Animal(const std::string& name);
    virtual ~Animal();
    virtual void speak() const = 0;
    virtual void info() const = 0;
};
