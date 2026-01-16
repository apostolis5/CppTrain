#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include "atm.h" 
#include "bank_internal_system.h" 
#include "bank_account.h"
using namespace std;

TEST_CASE("ATM and BankInternalSystem integration scenario", "[ATM_Integration]") {
    BankInternalSystem internal_system;
    ATM my_atm(internal_system);

    // Scenario: BankInternalSystem creates two accounts, then next  day a customer via ATM operates on them.

    // 1. BankInternalSystem creates a new account
    string creation_message = internal_system.create_account("1001", "Customer A", 500);
    REQUIRE(creation_message == "Account 1001 created successfully for Customer A.");
    REQUIRE(internal_system.get_account_for_customer("1001") != nullptr);
    REQUIRE(internal_system.get_balance_for_customer("1001") == 500);

    // Add another account to the system to ensure multiple accounts are handled
    string creation_message_2 = internal_system.create_account("1002", "Customer B", 300);
    REQUIRE(creation_message_2 == "Account 1002 created successfully for Customer B.");
    REQUIRE(internal_system.get_account_for_customer("1002") != nullptr);
    REQUIRE(internal_system.get_balance_for_customer("1002") == 300);

    // Perform ATM operations on the two accounts
    //  ATM displays initial balance of first account
    string display_initial = my_atm.display_balance("1001");
    REQUIRE(display_initial == "Account 1001 has balance --> 500");

    //  ATM deposits money first account
    string deposit_message = my_atm.make_deposit("1001", 100);
    REQUIRE(deposit_message == "Deposit of 100 to account 1001 processed. New balance: 600.");
    REQUIRE(internal_system.get_balance_for_customer("1001") == 600); // Verify internal state

    //  ATM withdraws money first account
    string withdrawal_message = my_atm.make_withdrawal("1001", 150);
    REQUIRE(withdrawal_message == "Withdrawal of 150 from account 1001 processed. New balance: 450.");
    REQUIRE(internal_system.get_balance_for_customer("1001") == 450); // Verify internal state

    // ATM displays final balance first account
    string display_final = my_atm.display_balance("1001");
    REQUIRE(display_final == "Account 1001 has balance --> 450");



    // test atm operations on second account
    // ATM displays initial balance of second account
    string display_initial_2 = my_atm.display_balance("1002");
    REQUIRE(display_initial_2 == "Account 1002 has balance --> 300");           
    // ATM deposits money to second account 
    string deposit_message_2 = my_atm.make_deposit("1002", 200);
    REQUIRE(deposit_message_2 == "Deposit of 200 to account 1002 processed. New balance: 500.");
    REQUIRE(internal_system.get_balance_for_customer("1002") == 500); // Verify internal state
    // ATM withdraws money from second account
    string withdrawal_message_2 = my_atm.make_withdrawal("1002", 100);
    REQUIRE(withdrawal_message_2 == "Withdrawal of 100 from account 1002 processed. New balance: 400.");
    REQUIRE(internal_system.get_balance_for_customer("1002") == 400); // Verify internal state


    



    // ATM attempts a failed withdrawal (insufficient funds)
    string failed_withdrawal_message = my_atm.make_withdrawal("1001", 500);
    REQUIRE(failed_withdrawal_message == "Withdrawal failed for account 1001: Withdrawal amount exceeds balance.");
    REQUIRE(internal_system.get_balance_for_customer("1001") == 450); // Balance should remain unchanged

    //  ATM attempts operations on a non-existent account
    string non_existent_display = my_atm.display_balance("9999");
    REQUIRE(non_existent_display == "Error: Account 9999 not found for balance inquiry.");

    string non_existent_deposit = my_atm.make_deposit("9999", 100);
    REQUIRE(non_existent_deposit == "Error: Account 9999 not found for deposit.");

    string non_existent_withdrawal = my_atm.make_withdrawal("9999", 50);
    REQUIRE(non_existent_withdrawal == "Error: Account 9999 not found for withdrawal.");
}