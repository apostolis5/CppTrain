#pragma once
#include "bank_account.h"

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int balance) : BankAccount(balance) 
    {
    }
};