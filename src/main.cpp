#include <iostream>
#include "bank_account.h"
#include "atm.h"
#include <string>

using namespace std;


int main() {
cout << endl;
cout << endl;

    
    string s1 = "Hello, World!"; 
    cout << s1 << endl;

    BankAccount default_account;
    cout << "Default Account Balance: " << default_account.get_balance() << endl;

    BankAccount account(4000);
    cout << "Account Balance: " << account.get_balance() << endl;

    account.deposit(300);
    cout << "After depositing , Account Balance: " << account.get_balance() << endl;

    account.withdraw(500);
    cout << "After withdraw , Account Balance: " << account.get_balance() << endl;

    ATM atmDefault;
    atmDefault.display_balance();

    ATM atm1(account);    
    atm1.display_balance();

    cout << endl;

    BankAccount account2(10000);
    ATM atm2(account2);
    account2.withdraw(1000);
    
    atm2.display_balance();

    


cout << endl;
cout << endl;
return 0;
}