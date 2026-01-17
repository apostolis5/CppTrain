#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
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

    // Initialize and link BankInternalSystem with ATM
    BankInternalSystem bankSystem;
    ATM piraeusAtm(bankSystem);

    // Create accounts within the banking system
    bankSystem.create_account("001", "work_account", 5000);
    bankSystem.create_account("002", "personal_account", 3000);
    bankSystem.create_account("***", "new account", 10);
    
    cout << "Welcome to the Piraeus Bank ATM!\n";

    string selectedAccountId;

    while (true) {
        cout << "\n=====================================\n";
        cout << "           AVAILABLE ACCOUNTS        \n";
        cout << "=====================================\n";
        
        // Dynamically list accounts
        const vector<BankAccount>& accounts = bankSystem.get_all_accounts();
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

            int amount;
            string response;

            switch (choice) {
                case 1: // Display Balance
                    response = piraeusAtm.display_balance(selectedAccountId);
                    cout << "Current Balance: " << response << endl;
                    break;
                case 2: // Deposit
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    response = piraeusAtm.make_deposit(selectedAccountId, amount);
                    if (response == "200 OK") {
                        cout << "Deposit successful." << endl;
                        cout << "New Balance: " << piraeusAtm.display_balance(selectedAccountId) << endl;
                    } else {
                        cout << "Deposit failed: " << response << endl;
                    }
                    break;
                case 3: // Withdraw
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    response = piraeusAtm.make_withdrawal(selectedAccountId, amount);
                     if (response == "200 OK") {
                        cout << "Withdrawal successful." << endl;
                        cout << "New Balance: " << piraeusAtm.display_balance(selectedAccountId) << endl;
                    } else {
                        cout << "Withdrawal failed: " << response << endl;
                    }
                    break;
                case 4: // Choose a different account
                    accountMenu = false;
                    break;
                case 5: // Exit ATM
                    cout << "Thank you for using the ATM Banking System. Goodbye!\n";
                    return 0; // Exit the program
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }    

    cout << "Thank you for using the ATM Banking System. Goodbye!\n";
    return 0;
}
