//ATM core business logic 
#include "atm.h" // Include the new ATM header
#include <iostream>
#include <optional> 
#include <string> 
using namespace std;

// Constructor definition
ATM::ATM(BankInternalSystem& system) : bank_system(system) {};

string ATM::display_balance(const string& accountId) {
    optional<int> balance = bank_system.get_balance_for_customer(accountId); // Use a distinct name
    if (balance.has_value()) 
    
    return to_string(balance.value()); // Just return the balance as a string
}

string ATM::make_deposit(const string& accountId, int amount) {
    return bank_system.deposit_to_account(accountId, amount);
}

string ATM::make_withdrawal(const string& accountId, int amount) {
    return bank_system.withdraw_from_account(accountId, amount);
}