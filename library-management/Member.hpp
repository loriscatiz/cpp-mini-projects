#include <map>
#include <string>

#include "Book.hpp"

#pragma once

class Member {
   private:
    static int previousId;
    int id;
    std::string name;
    std::map<int, Book> borrowedBooks;

   public:
    Member(std::string name);
    ~Member();
    int returnBook(int id);
    void borrowBook(Book& copy);
    void printBooks() const;
};