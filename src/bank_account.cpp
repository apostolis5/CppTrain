//Bank Account core business logic 
#include "bank_account.h"
#include "bank_internal_system.h" 
#include <stdexcept> 
#include <string>

// Constructor with member initializer list
BankAccount::BankAccount(string id, string username, int initial_balance) : 
                        accountId(id), accountUsername(username), balance(initial_balance) {}

// Getters
string BankAccount::get_accountId() const {
    return accountId;
}
string BankAccount::get_accountUsername() const {
    return accountUsername;
}
int BankAccount::get_balance() const {
    return balance;
}
// Setters
void BankAccount::set_accountUsername(const string& new_username) {
    accountUsername = new_username;
}

// Account transaction methods
void BankAccount::deposit(int amount) {
    if(amount > 0) { 
        balance += amount; }
}

void BankAccount::withdraw(int amount) {
    if (amount <= 0) {return;}
    if (amount > balance) {
        throw std::runtime_error("Withdrawal amount exceeds balance.");
    }
    
    balance -= amount;
}