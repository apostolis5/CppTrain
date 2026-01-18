//ATM core business logic 
#include "atm.h" 
#include <iostream>
#include <optional> 
#include <string> 
using namespace std;

// Constructor 
ATM::ATM(BankInternalSystem& system) : bank_system(system) {};

string ATM::display_balance(const string& accountId) {
    int balance = bank_system.get_balance_for_accountID(accountId); 
    if (balance != -1) {
        return to_string(balance);
    } else {
        return "Error";
    }
}

// Deposit funds into an account using the internal bank system and not directly manipulating accounts
string ATM::make_deposit(const string& accountId, int amount) {
    return bank_system.deposit_to_account(accountId, amount);
}

string ATM::make_withdrawal(const string& accountId, int amount) {
    return bank_system.withdraw_from_account(accountId, amount);
}