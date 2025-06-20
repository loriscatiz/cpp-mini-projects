#include "transaction.hpp"

Transaction::Transaction(Type type, int amount) : type(type), amount(amount) {}

Type Transaction::getType() const { return type; }

int Transaction::getAmount() const { return amount; }
