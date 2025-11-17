//atm.h
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
using std::cout; using std::cin; using std::unique_ptr; using std::vector;


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

// free functions 
void display_atm_menu();

void run_atm_session(ATM& atm);

