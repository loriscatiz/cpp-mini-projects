#include <iostream>

#include "transaction.hpp"
#include "wallet.hpp"

int main(int argc, char const* argv[]) {
    Wallet wallet;
    std::cout << "=== WELCOME TO THE WALLET APP ===\n";

    std::cout << "You initially have " << wallet.getBalance() << " cents\n";

    Transaction t1 = Transaction(Type::DEPOSIT, 20);
    wallet.operate(t1);

    std::cout << "You deposited " << t1.getAmount() << " cents\n";
    std::cout << "You now have " << wallet.getBalance() << " cents\n";

    Transaction t2 = Transaction(Type::WITHDRAW, 15);
    wallet.operate(t2);

    std::cout << "You withdrawn " << t2.getAmount() << " cents\n";
    std::cout << "You now have " << wallet.getBalance() << " cents\n";

    std::cout << "Your final balance is " << wallet.getBalance() << " cents\n";
    return 0;
}
