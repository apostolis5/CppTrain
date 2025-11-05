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

void BankAccount::withdraw(int amount)
{
    if(amount > 0 && amount <= balance)
    {
        balance -= amount;
    }
}