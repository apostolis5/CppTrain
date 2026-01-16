//bank_account.h
#pragma once
#include<iostream>
using namespace std;

class BankAccount
{
private:
    int balance;

public:
    // Default constructor initializes balance to 0
    BankAccount() {balance = 0;};
    // Constructor to initialize the balance
    BankAccount(int initial_balance) : balance(initial_balance) {};

    virtual int get_balance() const;
    virtual void deposit(int amount);
    virtual void withdraw(int amount);
};