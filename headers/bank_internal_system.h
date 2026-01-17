#pragma once
#include <string>
#include <vector>
#include <optional> 
#include "bank_account.h"
using namespace std;

class BankInternalSystem {
private:
    vector<BankAccount> bankAccountsDB; // Internal storage of all bank accounts

    // Returns a selected account
    BankAccount* find_account(const string& accountId);
    
public:
    BankInternalSystem() = default;

    // Clerk functionalities
    string create_account(const string& id, const string& username, int initial_balance);
    string delete_accountID(const string& accountId);


    // Customer-facing functionalities (delegated from ATM)
    BankAccount* get_account_for_customer(const string& accountId); 
    string deposit_to_account(const string& accountId, int amount);
    string withdraw_from_account(const string& accountId, int amount);
    int get_balance_for_accountID(const string& accountId); 

    // Method to get all accounts for display
    const vector<BankAccount>& get_all_accountsData() const;
};