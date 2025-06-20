#pragma once
#include <string>
#include <vector>

#include "transaction.hpp"

class Wallet {
   private:
    int balance;
    std::vector<Transaction> transactions;
    void deposit(int amount);
    void withdraw(int amount);

   public:
    Wallet();
    int getBalance() const;
    void operate(Transaction transaction);
};
