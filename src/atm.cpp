//ATM core business logic 
//  ENCAPSULATION of BankAccount within ATM
#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
#include <string> // Required for std::string
using namespace std; 

class ATM {
private:
    vector<BankAccount> bank_accounts_database; 

public:
    ATM() = default; // Default constructor
    void add_account(const BankAccount& acc);
    BankAccount* find_account(const string& accountId);
    void display_balance(const string& accountId);
    void make_deposit(const string& accountId, double amount);
    void make_withdrawal(const string& accountId, double amount);
    void display_all_balances();
};

inline void ATM::add_account(const BankAccount& acc) {
    bank_accounts_database.push_back(acc);
}

inline BankAccount* ATM::find_account(const string& accountId) {
    for (auto& account : bank_accounts_database) {
        if (account.get_accountId() == accountId) { // Renamed getter
            return &account;
        }
    }
    return nullptr; // Account not found
}

inline void ATM::display_balance(const string& accountId) {
    BankAccount* account = find_account(accountId);
    if (account) {
        cout << "Account " << accountId << " has balance --> " << account->get_balance() << "\n";
    } else {
        cout << "Account " << accountId << " not found.\n";
    }
}

inline void ATM::make_deposit(const string& accountId, double amount) {
    BankAccount* account = find_account(accountId);
    if (account) {
        account->deposit(static_cast<int>(amount)); // Cast to int
        cout << "Deposited " << amount << " into account " << accountId << ". New balance: " << account->get_balance() << "\n";
    } else {
        cout << "Account " << accountId << " not found for deposit.\n";
    }
}

inline void ATM::make_withdrawal(const string& accountId, double amount) {
    BankAccount* account = find_account(accountId);
    if (account) {
        account->withdraw(static_cast<int>(amount)); // Cast to int
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
    for (const auto& account : bank_accounts_database) {
        cout << "Account ID: " << account.get_accountId() // Renamed getter
             << ", Username: " << account.get_accountUsername() // Renamed getter
             << ", Balance: " << account.get_balance() << "\n";
    }
    cout << "----------------------------\n";
}
