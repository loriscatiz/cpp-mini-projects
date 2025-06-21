#include "Member.hpp"

#include <iostream>

int Member::previousId = 0;

Member::Member(std::string name) : name(name), id(++previousId) {}

Member::~Member() {}

int Member::returnBook(int id) {
    borrowedBooks.erase(id);
    return id;
}

void Member::borrowBook(Book& copy) { borrowedBooks.insert({id, copy}); }

void Member::printBooks() const {
    std::cout << "All books currently borrowed by: " << name << '\n';

    if (borrowedBooks.size() == 0) {
        std::cout << "No books currently borrowed\n\n";
    }

    for (const auto& [key, val] : borrowedBooks) {
        val.print();
    }
}
