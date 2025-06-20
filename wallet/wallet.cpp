#include "wallet.hpp"

#include <iostream>

void Wallet::deposit(int amount) { balance += amount; }

void Wallet::withdraw(int amount) {
    if (amount > balance) {
        std::cout << "Insufficient funds\n";
        return;
    }

    balance -= amount;
}

Wallet::Wallet() : balance(0) {}

int Wallet::getBalance() const { return balance; }

void Wallet::operate(Transaction transaction) {
    int amount = transaction.getAmount();

    if (amount < 0) {
        std::cout << "Invalid transaction: amount must be positive\n";
        return;
    }

    switch (transaction.getType()) {
        case Type::DEPOSIT:
            deposit(amount);
            return;
        case Type::WITHDRAW:
            withdraw(amount);
            return;
    }
}
