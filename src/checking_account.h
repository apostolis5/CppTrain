#pragma once
#include "bank_account.h"
#include <iostream>
using namespace std;

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount() : BankAccount() 
    {
        cout << "CheckingAccount Default Constructor called"  << endl;
    }

    CheckingAccount(int balance) : BankAccount(balance) {}

};