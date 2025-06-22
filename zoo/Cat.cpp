#include "Cat.hpp"

#include <iostream>

#include "Animal.hpp"

Cat::Cat(const std::string& name) : Animal(name) {}

void Cat::speak() const { std::cout << "Meow meow\n"; }

void Cat::info() const { std::cout << "I am a cat and my name is " << name << '\n'; }