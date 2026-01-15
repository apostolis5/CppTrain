//  ENCAPSULATION of BankAccount within ATM
#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
using namespace std;


class ATM
{
private:
    BankAccount* account;
    vector<BankAccount> accounts;
public:
    ATM(BankAccount& acc) : account(&acc) {}
    ATM();
    void display_balance();
    void add_account(const BankAccount& acc);
    void display_accounts();
    void make_deposit();
    void make_withdrawal();
};

// free functions 
void display_atm_menu();

void run_atm_session(ATM& atm);

inline ATM::ATM() { }

inline void ATM::add_account(const BankAccount& acc)
{
    accounts.push_back(acc);
}

inline void ATM::display_accounts()
{
    for(size_t i = 0; i < accounts.size(); ++i)
    {
        cout << "Saved Account " << i << " Balance: " << accounts[i].get_balance() << endl;
    }
}

inline void ATM::display_balance()
{
    if (account)
        cout<<"Current Account of ATM has balance --> "<< account->get_balance() <<"\n";
}

inline void ATM::make_deposit() 
{
    if (!account) return;
    int amount = 0;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    account->deposit(amount);
}

inline void ATM::make_withdrawal() 
{
    if (!account) return;
    int amount = 0;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    
    account->withdraw(amount);
}

// free functions 
inline void display_atm_menu()
{
    cout << "--------ATM MENU-----------\n";
    cout << "1. Display Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
}

inline void run_atm_session(ATM& atm)
{
    int option = 0;
    do {
        cout << endl;
        cout << endl;
        display_atm_menu();
        cout << "Enter your choice --> ";
        
        cin >> option;
        switch (option) {
            case 1:
                atm.display_balance();
                break;
            case 2:
                atm.make_deposit();
                break;
            case 3:
                atm.make_withdrawal();
                break;
            case 4:
                cout << "Exiting ATM session........\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (option != 4);
}
