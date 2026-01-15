#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bank_account.h"
#include "checking_account.h"
#include "atm.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("BankAccount operations", "[account]") {
    BankAccount default_account;
    REQUIRE(default_account.get_balance() == 0);

    BankAccount account(4000);
    REQUIRE(account.get_balance() == 4000);

    account.deposit(300);
    REQUIRE(account.get_balance() == 4300);

    account.withdraw(500);
    REQUIRE(account.get_balance() == 3800);
}

TEST_CASE("ATM Encapsulation and Interaction", "[atm]") {
    BankAccount account(9000);
    ATM atm(account);

    SECTION("Deposit via ATM") {
        // Simulate user input "500"
        std::stringstream input("500");
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

        atm.make_deposit();

        std::cin.rdbuf(oldCin); // Restore cin

        REQUIRE(account.get_balance() == 9500);
    }

    SECTION("Withdrawal via ATM") {
        // Simulate user input "1000"
        std::stringstream input("1000");
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

        atm.make_withdrawal();

        std::cin.rdbuf(oldCin); // Restore cin

        REQUIRE(account.get_balance() == 8000);
    }
}

TEST_CASE("Inheritance with CheckingAccount", "[inheritance]") {
    CheckingAccount check1;
    REQUIRE(check1.get_balance() == 0); // Default constructor

    check1.deposit(500);
    REQUIRE(check1.get_balance() == 500);

    // Test polymorphism via ATM
    ATM atm(check1);
    
    // Simulate deposit "200"
    std::stringstream input("200");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    
    atm.make_deposit();
    
    std::cin.rdbuf(oldCin);
    
    REQUIRE(check1.get_balance() == 700);
}

TEST_CASE("ATM Vector of Accounts", "[vector]") {
    ATM multiAccountATM;
    BankAccount a1(100);
    BankAccount a2(200);

    multiAccountATM.add_account(a1);
    multiAccountATM.add_account(a2);

    // Capture stdout to verify display_accounts output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    multiAccountATM.display_accounts();
    
    std::cout.rdbuf(oldCout);
    
    std::string output = buffer.str();
    REQUIRE(output.find("Saved Account 0 Balance: 100") != std::string::npos);
    REQUIRE(output.find("Saved Account 1 Balance: 200") != std::string::npos);
}


                                                                        
                                                                    // previous content of src/main.cpp
/*
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
*/ 
