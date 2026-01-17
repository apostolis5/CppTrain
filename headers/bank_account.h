//bank_account.h
#pragma once
#include<iostream>
#include<string> 
using namespace std;

// Forward declaration to break circular dependency
class BankInternalSystem;

class BankAccount
{
private:
    string accountId;
    string accountUsername;
    int balance;

public:
    // Constructor to initialize all details of a bank account
    BankAccount(string accountId, string accountUsername, int initial_balance);

    // Method to register this account with the banking system
    string register_to_system(BankInternalSystem& system);

    // Getter methods
    string get_accountId() const;
    string get_accountUsername() const;
    int get_balance() const;

    // Transaction methods
    void deposit(int amount);
    void withdraw(int amount);
};