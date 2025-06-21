#include "Book.hpp"

#include <iostream>

int Book::previousId = 0;

Book::Book(const Book& original)
    : id(original.id), author(original.author), title(original.title), isAvailable(true) {}

Book::Book(std::string author, std::string title)
    : id(++previousId), author(author), title(title), isAvailable(true) {}

Book::~Book() {}

int Book::getId() const { return id; }

std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

bool Book::getIsAvailable() const { return isAvailable; }

void Book::setIsAvailable(bool status) { isAvailable = status; }

void Book::print() const {
    std::cout << "id: " << id << " Author: " << getAuthor() << " Title: " << getTitle()
              << " Availability: " << getIsAvailable() << "\n\n";
}
