#pragma once
#include <string>
#include "bank_internal_system.h" // ATM needs to know about BankInternalSystem
using namespace std;

class ATM {
private:
    BankInternalSystem& bank_system; 

public:
    ATM(BankInternalSystem& system);

    string display_balance(const string& accountId); 
    string make_deposit(const string& accountId, int amount);
    string make_withdrawal(const string& accountId, int amount);
};