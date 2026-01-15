#include <iostream>
#include "bank_account.h"
#include "checking_account.h"
#include "atm.h"
#include <string>

using namespace std;


int main() {
cout << endl << endl << endl;

    
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


    cout << endl << endl;
    cout << "       ENCAPSULATION     " << endl;
    cout << "--------------------------------" << endl;

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
    
    // Create a BankAccount with an initial balance of 5000 and connect it to an ATM frontEnd
    cout << " ********* Mis8odosia Account *******   " << endl; 
    BankAccount Mis8odosia(3875);
    // Connect Account to ATM
    ATM EurobankATM(Mis8odosia);
    // Run an interactive ATM session
    run_atm_session(EurobankATM);
    cout << endl;
    EurobankATM.display_balance();  

    //cout << endl;
    cout << endl;

    cout << " ********* Apotamieutikos Account *******   " << endl; 
    BankAccount Apotamieutikos(36);
    EurobankATM = ATM(Apotamieutikos); 
    // Run an interactive ATM session
    run_atm_session(EurobankATM);
    cout << endl;
    EurobankATM.display_balance();  

    cout << endl << endl;

    // load any of the trwo accounts and perform atm actions
    EurobankATM = ATM(Mis8odosia); 
    cout << "Mis8odosia balance -->  " ; 
    EurobankATM.display_balance();   
    
    EurobankATM = ATM(Apotamieutikos); 
    cout << "Apotamieutikos balance -->  " ; 
    EurobankATM.display_balance();  

    cout << endl << endl;
    cout << "       INHERITANCE     " << endl;
    cout << "--------------------------------" << endl;


    CheckingAccount check1;
    // we can use get_balance() method inherited from BankAccount , even though we did not redefine it in CheckingAccount
    // we can use get_balance() method because virtual (if not virtual we cannot use it)
    // also note that the Default constructor of BankAccount is called first, then the one of CheckingAccount (first base then derived) 
    cout << "Default CheckingAccount Balance: " << check1.get_balance() << endl; 

    check1.deposit(500);
    cout << "Default CheckingAccount Balance: " << check1.get_balance() << endl; 
    
    cout << endl << endl;
    
    // load CheckingAccount into ATM and perform atm actions to account check1
    EurobankATM = ATM(check1);
    EurobankATM.display_balance();
    EurobankATM.make_deposit();
    EurobankATM.display_balance();
    run_atm_session(EurobankATM);
    EurobankATM.display_balance();

    cout << endl << endl;
    cout << "       VECTOR IN ATM     " << endl;
    cout << "--------------------------------" << endl;

    ATM AlphaBankATM;
    AlphaBankATM.add_account(account);      // Save first account
    AlphaBankATM.add_account(Mis8odosia);   // Save second account
    cout << "Successfully saved 2 accounts into the ATM's internal vector." << endl;
    AlphaBankATM.display_accounts();

cout << endl << endl << endl;
return 0;
}