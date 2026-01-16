//ATM core business logic 
//  ENCAPSULATION of BankAccount within ATM
#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
#include <string> 
using namespace std; 

class ATM {
private:
    vector<BankAccount> bank_accounts_database; 

public:
    ATM() = default; // Default constructor
    void add_account(const BankAccount& acc);
    BankAccount* find_account(const string& accountId);
    void display_balance(const string& accountId);
    void make_deposit(const string& accountId, int amount);
    void make_withdrawal(const string& accountId, int amount);
    void display_all_balances();
};


inline void ATM::add_account(const BankAccount& acc) {
    bank_accounts_database.push_back(acc);
}


inline BankAccount* ATM::find_account(const string& accountId) {
    for (BankAccount& account : bank_accounts_database) {
        if (account.get_accountId() == accountId) { 
            return &account;

        }
    }
    return nullptr; 
}


inline void ATM::display_balance(const string& accountId) {
    BankAccount* account = find_account(accountId);
    
    if (account) {
        cout << "Account " << accountId << " has balance --> " << account->get_balance() << "\n";
    } else {
        cout << "Account " << accountId << " not found.\n";
    }
}


inline void ATM::make_deposit(const string& accountId, int amount) {
    BankAccount* account = find_account(accountId);
        if (account) {
    account->deposit(amount);
    
    cout << "Deposited " << amount << " into account " << accountId << ". New balance: " << account->get_balance() << "\n";
    } else {
        cout << "Account " << accountId << " not found for deposit.\n";
    }
}



inline void ATM::make_withdrawal(const string& accountId, int amount) {
    BankAccount* account = find_account(accountId);
        if (account) {
    account->withdraw(amount);

    cout << "Withdrew " << amount << " from account " << accountId << ". New balance: " << account->get_balance() << "\n";
    } else {
        cout << "Account " << accountId << " not found for withdrawal.\n";
    }
}



inline void ATM::display_all_balances() {
    if (bank_accounts_database.empty()) {
    cout << "No accounts in the ATM system.\n";
        return;
    }
    cout << "\n--- All Account Balances ---\n";
    
    for (const BankAccount& account : bank_accounts_database) {
        cout << "Account ID: " << account.get_accountId() 
             << ", Username: " << account.get_accountUsername()
             << ", Balance: " << account.get_balance() << "\n";
    }
    cout << "----------------------------\n";
}
