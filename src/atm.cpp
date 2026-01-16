//ATM core business logic 
#include "atm.h" // Include the new ATM header
#include <iostream>
#include <optional> 
#include <string> 
using namespace std;

// Constructor definition
ATM::ATM(BankInternalSystem& system) : bank_system(system) {};

string ATM::display_balance(const string& accountId) {
    optional<int> balance = bank_system.get_balance_for_customer(accountId);
    if (balance) {
        return "Account " + accountId + " has balance --> " + std::to_string(balance.value());
    } else {
        return "Error: Account " + accountId + " not found for balance inquiry.";
    }
}

string ATM::make_deposit(const string& accountId, int amount) {
    return bank_system.deposit_to_account(accountId, amount);
}

string ATM::make_withdrawal(const string& accountId, int amount) {
    return bank_system.withdraw_from_account(accountId, amount);
}