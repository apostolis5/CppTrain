//bank_account.h
#pragma once
#include<iostream>
using namespace std;

class BankAccount
{
private:
    int balance;

public:
    BankAccount() {   // Default constructor initializes balance to 0
        balance = 0;
        cout << "BankAccount Default Constructor called"  << endl;
    }

    BankAccount(int initial_balance) : balance(initial_balance) {    // Constructor to initialize the balance
        cout << "BankAccount created with initial balance: " << balance << endl;
    }

    virtual int get_balance() const;

    virtual void deposit(int amount);
    
    virtual void withdraw(int amount);

};