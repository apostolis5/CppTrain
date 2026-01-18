#pragma once
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include "bank_account.h"
using namespace std;

class BankInternalSystem {
private:
    vector<shared_ptr<BankAccount>> bankAccountsDB; // Internal storage of all bank accounts

    // Returns a selected account
    shared_ptr<BankAccount> find_account(const string& accountId);
    
public:
    BankInternalSystem() = default;

    // Clerk functionalities
    string register_account(shared_ptr<BankAccount> new_account);
    shared_ptr<BankAccount> get_account_for_customer(const string& accountId); 
    string deposit_to_account(const string& accountId, int amount);
    string withdraw_from_account(const string& accountId, int amount);
    int get_balance_for_accountID(const string& accountId);
    
    // Declare Edit and Delete Account Methods
    string delete_account(const string& accountId);
    string edit_account_username(const string& accountId, const string& new_username);

    // Method to get all accounts for display
    const vector<shared_ptr<BankAccount>>& get_all_accountsData() const;
};