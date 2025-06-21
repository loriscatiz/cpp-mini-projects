#include <iostream>

#include "Book.hpp"
#include "Library.hpp"
#include "Member.hpp"

int main(int argc, char const* argv[]) {
    Library library;

    Book book1 = Book("Andy", "title");
    Book book2 = Book("Bob", "good book");
    Book book3 = Book("Carl", "something");

    library.addNewBook(book1);
    library.addNewBook(book2);
    library.addNewBook(book3);

    Member user = Member("Loris");

    std::cout << "Initial state\n\n";
    library.printBooks();
    user.printBooks();

    Book copy = library.lendBook(1);
    user.borrowBook(copy);

    std::cout << "One book borrowed\n\n";
    library.printBooks();
    user.printBooks();

    user.returnBook(1);
    library.restoreBook(1);

    std::cout << "One book returned\n\n";
    library.printBooks();
    user.printBooks();

    return 0;
}
