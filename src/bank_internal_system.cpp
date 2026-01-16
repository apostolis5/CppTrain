#include "bank_internal_system.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <optional>
#include <vector> 
using namespace std;

// Helper to find an account by ID internally
BankAccount* BankInternalSystem::find_account_by_id_internal(const string& accountId) {
    for (auto& account : all_bank_accounts) {
        if (account.get_accountId() == accountId) {
            return &account;
        }
    }
    return nullptr;
}

// Clerk functionalities
string BankInternalSystem::create_account(const string& id, const string& username, int initial_balance) {
    if (find_account_by_id_internal(id) != nullptr) {
        return "Error";
    }
    all_bank_accounts.emplace_back(id, username, initial_balance);
    return "200 OK";
}

string BankInternalSystem::delete_account_by_id(const string& accountId) {
    for (auto it = all_bank_accounts.begin(); it != all_bank_accounts.end(); ++it) {
        if (it->get_accountId() == accountId) {
            it = all_bank_accounts.erase(it);
            return "200 OK";
        }
    }
    return "Error";
}

// Customer-facing functionalities (delegated from ATM)
BankAccount* BankInternalSystem::get_account_for_customer(const string& accountId) {
    return find_account_by_id_internal(accountId);
}

string BankInternalSystem::deposit_to_account(const string& accountId, int amount) {
    BankAccount* account = find_account_by_id_internal(accountId);
    if (account) {
        account->deposit(amount);
        return "200 OK";
    } else {
        return "Error";
    }
}

string BankInternalSystem::withdraw_from_account(const string& accountId, int amount) {
    BankAccount* account = find_account_by_id_internal(accountId);
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

int BankInternalSystem::get_balance_for_customer(const string& accountId) {
    BankAccount* account = find_account_by_id_internal(accountId);
    if (account) {
        return account->get_balance();
    }
    return -1; // Indicate account not found
}


