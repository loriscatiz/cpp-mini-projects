#include "Library.hpp"

#include <iostream>
Library::Library() {}

Library::~Library() {}

void Library::addNewBook(const Book& toAdd) { books.insert({toAdd.getId(), toAdd}); }

void Library::removeBook(const int id) { books.erase(id); }

void Library::updateBook(const int id, const Book& updated) {
    books.erase(id);
    addNewBook(updated);
}

Book Library::peekById(const int id) const { return books.at(id); }

Book Library::lendBook(const int id) {
    Book& original = books.at(id);
    original.setIsAvailable(false);

    Book toLend = Book(original);
    return toLend;
}

void Library::restoreBook(const int id) { books.at(id).setIsAvailable(true); }

void Library::printBooks() const {
    std::cout << "All books in the library\n";

    for (const auto& [key, val] : books) {
        val.print();
    }
}
