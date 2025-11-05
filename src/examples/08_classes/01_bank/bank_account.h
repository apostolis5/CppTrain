//bank_account.h
#include<iostream>
using namespace std;

class BankAccount
{
private:
    int Balance;

public:
    BankAccount() {   // Default constructor initializes balance to 0
        Balance = 0;
        cout << "BankAccount Default Constructor called"  << endl;
    }

    BankAccount(int initial_balance) : Balance(initial_balance) {    // Constructor to initialize the balance
        cout << "BankAccount created with initial balance: " << Balance << endl;
    }

    int get_balance() { 
        return Balance;
    }

};