#include <iostream>
#include "bank_account.h"
#include <string>

using namespace std;


int main()
{   
    string s1 = "Hello, World!"; 
    cout << s1 << endl;

    BankAccount default_account;
    cout << "Default Account Balance: " << default_account.get_balance() << endl;

    BankAccount account(3875);
    cout << "Account Balance: " << account.get_balance() << endl;






return 0;
}