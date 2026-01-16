//bank_account.h
#pragma once
#include<iostream>
#include<string> 
using namespace std;

class BankAccount
{
private:
    string accountId;
    string accountUsername;
    int balance;

public:
    // Constructor to initialize all details of a bank account
    BankAccount(string accountId, string accountUsername, int initial_balance);

    // Getter methods
    string get_accountId() const;
    string get_accountUsername() const;
    int get_balance() const;

    // Transaction methods
    void deposit(int amount);
    void withdraw(int amount);
};