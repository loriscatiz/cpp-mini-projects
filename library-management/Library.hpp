#include <map>
#include <string>

#include "Book.hpp"

#pragma once

class Library {
   private:
    std::map<int, Book> books;

   public:
    Library();
    ~Library();
    void addNewBook(const Book& toAdd);
    void removeBook(const int id);
    void updateBook(const int id, const Book& updated);
    Book peekById(const int id) const;
    Book lendBook(const int id);
    void restoreBook(const int id);
    void printBooks() const;
};
