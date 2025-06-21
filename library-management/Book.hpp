#include <string>

#pragma once

class Book {
   private:
    static int previousId;
    int id;
    std::string title;
    std::string author;
    bool isAvailable;

   public:
    /// @brief Create a copy of the book to lend to a member.
    /// @param original the original book
    Book(const Book& original);

    /// @brief create a new book to add to the available books.
    /// @param author
    /// @param title
    Book(std::string author, std::string title);
    ~Book();

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getIsAvailable() const;
    void setIsAvailable(bool status);
    void print() const;
};
