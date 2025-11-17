//atm.h
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"



class ATM
{
private:
    BankAccount* account;
public:
    // default constructor
    ATM() : account(new BankAccount()) {} 

    ATM(BankAccount& acc) : account(&acc) {}
    
    void display_balance();

    void make_deposit();

    void make_withdrawal();
};