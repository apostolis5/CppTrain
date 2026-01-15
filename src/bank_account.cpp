//Bank Account core business logic 
#include "bank_account.h"
#include <stdexcept>

int BankAccount::get_balance() const {
    return balance;
}

void BankAccount::deposit(int amount) {
    if(amount > 0) { balance += amount; }
}

void BankAccount::withdraw(int amount) {
    if (amount > balance) {
        throw std::runtime_error("Withdrawal amount exceeds balance.");
    }
    
    if(amount > 0) { balance -= amount; }
}