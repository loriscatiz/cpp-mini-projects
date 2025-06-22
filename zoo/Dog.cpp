#include "Dog.hpp"

#include <iostream>

Dog::Dog(const std::string& name) : Animal(name) {}

void Dog::speak() const { std::cout << "Woff woff\n"; }

void Dog::info() const { std::cout << "I am a dog and my name is " << name << '\n'; }