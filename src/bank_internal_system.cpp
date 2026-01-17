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

// Clerk functionalities
string BankInternalSystem::create_account(const string& id, const string& username, int initial_balance) {
    if (find_account(id) != nullptr) {
        return "Error";
    }
    bankAccountsDB.emplace_back(id, username, initial_balance);
    // Alternatively:
    //bankAccountsDB.push_back(BankAccount(id, username, initial_balance));
    return "200 OK";
}

string BankInternalSystem::delete_accountID(const string& accountId) {
    for (auto it = bankAccountsDB.begin(); it != bankAccountsDB.end(); ++it) {
        if (it->get_accountId() == accountId) {
            it = bankAccountsDB.erase(it);
            return "200 OK";
        }
    }
    return "Error";
}


BankAccount* BankInternalSystem::get_account_for_customer(const string& accountId) {
    return find_account(accountId);
}

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

const vector<BankAccount>& BankInternalSystem::get_all_accountsData() const {
    return bankAccountsDB; // returns the internal vector
}