#pragma once

enum class Type { DEPOSIT, WITHDRAW };
class Transaction {
   private:
    Type type;
    int amount;

   public:
    Transaction(Type type, int amount);
    Type getType() const;
    int getAmount() const;
};
