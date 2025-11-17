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

    BankAccount account2(9000);
    ATM atm2(account2);
    atm2.make_deposit();
    atm2.make_withdrawal(); 
    
    atm2.display_balance();
    cout << "account2 balance -->  " << account2.get_balance() << endl;


    cout << endl;
    cout << endl;
    
    // Create a BankAccount with an initial balance of 5000 and connect it to an ATM frontEnd
    cout << " ********* Mis8odosia Account *******   " << endl; 
    BankAccount Mis8odosia(3875);
    // Connect Account to ATM
    ATM EurobankATM(Mis8odosia);
    // Run an interactive ATM session
    run_atm_session(EurobankATM);
    cout << endl;
    EurobankATM.display_balance();  

    cout << endl;
    cout << endl;

    cout << " ********* Apotamieutikos Account *******   " << endl; 
    BankAccount Apotamieutikos(36);
    EurobankATM = ATM(Apotamieutikos); 
    // Run an interactive ATM session
    run_atm_session(EurobankATM);
    cout << endl;
    EurobankATM.display_balance();  

    cout << endl;
    cout << endl;
    
    // load any of the trwo accounts and perform atm actions
    EurobankATM = ATM(Mis8odosia); 
    cout << "Mis8odosia balance -->  " << endl; 
    EurobankATM.display_balance();   
    
    EurobankATM = ATM(Apotamieutikos); 
    cout << "Apotamieutikos balance -->  " << endl; 
    EurobankATM.display_balance();  



cout << endl;
cout << endl;
return 0;
}