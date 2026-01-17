#pragma once
#include <string>
#include <vector>
#include <optional> 
#include "bank_account.h"
using namespace std;

class BankInternalSystem {
private:
    vector<BankAccount> all_bank_accounts;

    // Helper to find an account by ID
    BankAccount* find_account_by_id_internal(const string& accountId);
    
public:
    BankInternalSystem() = default;

    // Clerk functionalities
    string create_account(const string& id, const string& username, int initial_balance);
    string delete_account_by_id(const string& accountId);


    // Customer-facing functionalities (delegated from ATM)
    BankAccount* get_account_for_customer(const string& accountId); 
    string deposit_to_account(const string& accountId, int amount);
    string withdraw_from_account(const string& accountId, int amount);
    int get_balance_for_customer(const string& accountId); 

    // Method to get all accounts for display
    const vector<BankAccount>& get_all_accounts() const;
};