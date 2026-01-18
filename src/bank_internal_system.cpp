// Internal Banking System Core Business Logic 
#include "bank_internal_system.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <optional>
#include <vector> 
using namespace std;

// Returns an account searched by ID internally
BankAccount* BankInternalSystem::find_account(const string& accountId) {
    for (auto& account : bankAccountsDB) {
        if (account.get_accountId() == accountId) {
            return &account;
        }
    }
    return nullptr;
}

// Register a new account into the internal banking system
string BankInternalSystem::register_account(BankAccount new_account) {
    if (find_account(new_account.get_accountId()) != nullptr) {
        return "Error";
    }
    bankAccountsDB.push_back(new_account);
    return "200 OK";
}

// Implement Edit and Delete Account Methods    







BankAccount* BankInternalSystem::get_account_for_customer(const string& accountId) {
    return find_account(accountId);
}

const vector<BankAccount>& BankInternalSystem::get_all_accountsData() const {
    return bankAccountsDB; // returns the internal vector
}


// Below functions are customer-related operations used from ATM (ATM and internal system are connected)
// Also a bank clerk can use these functions to access an account through the internal bank system additionally
string BankInternalSystem::deposit_to_account(const string& accountId, int amount) {
    BankAccount* account = find_account(accountId);
    if (account) {
        account->deposit(amount);
        return "200 OK";
    } else {
        return "Error";
    }
}

string BankInternalSystem::withdraw_from_account(const string& accountId, int amount) {
    BankAccount* account = find_account(accountId);
    if (account) {
        try {
            account->withdraw(amount);
            return "200 OK";
        } catch (const runtime_error& e) {
            return "Error";
        }
    } else {
        return "Error";
    }
}

int BankInternalSystem::get_balance_for_accountID(const string& accountId) {
    BankAccount* account = find_account(accountId);
    if (account) {
        return account->get_balance();
    }
    return -1; 
}
