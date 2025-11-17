//atm.cpp
#include "atm.h"
using std::cin; using std::cout; using std::unique_ptr;



void ATM::display_balance()
{
    cout<<"Current Account of ATM has balance --> "<< account->get_balance() <<"\n";
}

void ATM::make_deposit() 
{
    int amount = 0;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    account->deposit(amount);
}

void ATM::make_withdrawal() 
{
    int amount = 0;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    
    account->withdraw(amount);
}