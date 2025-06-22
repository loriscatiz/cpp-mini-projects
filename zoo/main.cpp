#include <iostream>
#include <vector>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(int argc, char const* argv[]) {
    Dog dog = Dog("Tobi");
    Cat cat = Cat("Garfield");
    Dog scooby = Dog("Scooby");

    std::vector<Animal*> animals;

    animals.push_back(&dog);
    animals.push_back(&cat);
    animals.push_back(&scooby);

    for (auto a : animals) {
        a->info();
        (*a).speak();
    }
}
