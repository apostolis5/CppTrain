//ATM core business logic 
//  ENCAPSULATION of BankAccount within ATM
#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
using namespace std;


class ATM {
private:
    BankAccount* bank_account;    
    // database of bank accounts -> Vector Data Structure
    //vector<BankAccount>  bank_accounts_database; 
public:
    ATM(BankAccount& acc) : bank_account(&acc) {};
    void display_balance();
    //void add_account(const BankAccount& acc);
    void make_deposit(int amount);
    void make_withdrawal(int amount);
};


inline void ATM::display_balance() {
    if (bank_account)
        cout<<"Current Account of ATM has balance --> "<< bank_account->get_balance() <<"\n";
}

inline void ATM::make_deposit(int amount) {
    if (!bank_account) return;
    bank_account->deposit(amount);
}

inline void ATM::make_withdrawal(int amount) {
    if (!bank_account) return;
    bank_account->withdraw(amount);
}


//inline void ATM::add_account(const BankAccount& acc) {
//    bank_accounts_database.push_back(acc);
//}