//  ENCAPSULATION of BankAccount within ATM
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
using namespace std;


class ATM
{
private:
    BankAccount* account;
public:
    ATM(BankAccount& acc) : account(&acc) {}
    
    void display_balance();
    void make_deposit();
    void make_withdrawal();
};

// free functions 
void display_atm_menu();

void run_atm_session(ATM& atm);

void ATM::display_balance()
{
    if (account)
        cout<<"Current Account of ATM has balance --> "<< account->get_balance() <<"\n";
}

void ATM::make_deposit() 
{
    if (!account) return;
    int amount = 0;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    account->deposit(amount);
}

void ATM::make_withdrawal() 
{
    if (!account) return;
    int amount = 0;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    
    account->withdraw(amount);
}

// free functions 
void display_atm_menu()
{
    cout << "--------ATM MENU-----------\n";
    cout << "1. Display Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
}

void run_atm_session(ATM& atm)
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
