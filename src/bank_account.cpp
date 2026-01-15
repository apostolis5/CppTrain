//bank_account.cpp
#include "bank_account.h"

int BankAccount::get_balance() const
{
    return balance;
}

void BankAccount::deposit(int amount)
{
    if(amount > 0)
    {
        balance += amount;
    }
}

#include <stdexcept>

void BankAccount::withdraw(int amount)
{
    if (amount > balance) {
        throw std::runtime_error("Withdrawal amount exceeds balance.");
    }
    
    if (amount > 0) {
        balance -= amount;
    }
}