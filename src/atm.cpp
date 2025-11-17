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

