#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "bank_internal_system.h" 
#include "atm.h"                  
using namespace std;

int main(int argc, char* argv[]) {
    // Run Catch2 tests first
    int result = Catch::Session().run(argc, argv);
    if (result != 0) {
        cout << "Tests failed! Aborting simulation.\n";
        return result;
    }

    cout << "\n***************************Banking System Initialized***************************\n";

    // Initialize bank system
    BankInternalSystem bankSystem;
    ATM* piraeusAtm = new ATM(bankSystem);
    //ATM piraeusAtm(bankSystem);

    BankAccount* acc1 = new BankAccount("001", "work_account", 5000);
    BankAccount* acc2 = new BankAccount("002", "personal_account", 3000);
    BankAccount* acc3 = new BankAccount("003", "savings_account", 10000);
    // make accounts available both in the banking system and atm
    acc1->register_to_system(bankSystem);
    acc2->register_to_system(bankSystem);
    acc3->register_to_system(bankSystem);

        cout << "Welcome to the Piraeus Bank ATM!\n";

    string selectedAccountId;

    while (true) {
        cout << "\n=====================================\n";
        cout << "           AVAILABLE ACCOUNTS        \n";
        cout << "=====================================\n";
        
        // Dynamically list accounts
        const vector<BankAccount>& accounts = bankSystem.get_all_accountsData();
        for (const BankAccount& account : accounts) {
            cout << "  - Account ID: " << account.get_accountId() 
                 << " (" << account.get_accountUsername() << ")\n";
        }
        
        cout << "-------------------------------------\n";
        cout << "\nPlease enter the Account ID to access (or type 'exit' to quit): ";
        cin >> selectedAccountId;

        if (selectedAccountId == "exit") {
            break;
        }

        // Check if account exists
        if (bankSystem.get_account_for_customer(selectedAccountId) == nullptr) {
            cout << "Error: Account with ID '" << selectedAccountId << "' not found. Please try again.\n";
            continue;
        }

        bool accountMenu = true;
        while (accountMenu) {
            cout << "\n----- ATM Menu for Account: " << selectedAccountId << " -----\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Funds\n";
            cout << "3. Withdraw Funds\n";
            cout << "4. Choose a different account\n";
            cout << "5. Exit ATM\n";
            cout << "------------------------------------------\n";
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            int amount;
            string response;

            switch (choice) {
                case 1:
                    response = piraeusAtm->display_balance(selectedAccountId);
                    cout << "Current Balance: " << piraeusAtm->display_balance(selectedAccountId) << endl;
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    response = piraeusAtm->make_deposit(selectedAccountId, amount);
                    if (response == "200 OK") {
                        cout << "Deposit successful." << endl;
                        cout << "New Balance: " << piraeusAtm->display_balance(selectedAccountId) << endl;
                    } else {
                        cout << "Deposit failed: " << response << endl;
                    }
                    break;
                case 3:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    response = piraeusAtm->make_withdrawal(selectedAccountId, amount);
                     if (response == "200 OK") {
                        cout << "Withdrawal successful." << endl;
                        cout << "New Balance: " << piraeusAtm->display_balance(selectedAccountId) << endl;
                    } else {
                        cout << "Withdrawal failed: " << response << endl;
                    }
                    break;
                case 4:
                    accountMenu = false;
                    break;
                case 5:
                    cout << "Thank you for using the ATM Banking System. Goodbye!\n";
                    // Clean up dynamically allocated memory before exiting
                    delete acc1;
                    delete acc2;
                    delete acc3;
                    return 0; 
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }  








    // Clean up dynamically allocated memory before exiting
    delete acc1;
    delete acc2;
    delete acc3;
    delete piraeusAtm;
    cout << "\n\n\nThank you for using the ATM Banking System. Goodbye!\n\n\n";
    return 0;
}