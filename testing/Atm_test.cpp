#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include <sstream> 
#include "atm.h" 
#include "bank_internal_system.h" 
#include "bank_account.h"
using namespace std;

TEST_CASE("ATM and BankInternalSystem integration scenario", "[ATM_Integration]") {
    BankInternalSystem internal_system;
    ATM my_atm(internal_system);

    // Scenario: BankInternalSystem creates an account, then ATM operates on it.

    // 1. BankInternalSystem creates a new account
    string creation_result = internal_system.create_account("1001", "Customer A", 500);
    REQUIRE(creation_result == "200 OK");
    REQUIRE(internal_system.get_account_for_customer("1001") != nullptr);
    REQUIRE(internal_system.get_balance_for_customer("1001") == 500);

    // 2. ATM displays initial balance
    string display_initial = my_atm.display_balance("1001");
    REQUIRE(display_initial == "200 OK");

    // 3. ATM deposits money
    string deposit_message = my_atm.make_deposit("1001", 100);
    REQUIRE(deposit_message == "200 OK"); // ATM delegates, so expects "200 OK" from BIS
    
    // We should verify the internal state of the BankInternalSystem to ensure the deposit actually happened.
    REQUIRE(internal_system.get_balance_for_customer("1001") == 600); 

    // 4. ATM displays updated balance
    string display_after_deposit = my_atm.display_balance("1001");
    REQUIRE(display_after_deposit == "200 OK");

    // 5. ATM withdraws money
    string withdrawal_message = my_atm.make_withdrawal("1001", 150);
    REQUIRE(withdrawal_message == "200 OK"); // ATM delegates, so expects "200 OK" from BIS
    
    // We should verify the internal state of the BankInternalSystem to ensure the withdrawal actually happened.
    REQUIRE(internal_system.get_balance_for_customer("1001") == 450); 

    // 6. ATM displays final balance
    string display_final = my_atm.display_balance("1001");
    REQUIRE(display_final == "200 OK");

    // 7. ATM attempts a failed withdrawal (insufficient funds)
    string failed_withdrawal_message = my_atm.make_withdrawal("1001", 500);
    REQUIRE(failed_withdrawal_message == "Error"); // ATM delegates, so expects "Error" from BIS
    
    REQUIRE(internal_system.get_balance_for_customer("1001") == 450); // Balance should remain unchanged

    // 8. ATM attempts operations on a non-existent account
    string non_existent_display = my_atm.display_balance("9999");
    REQUIRE(non_existent_display == "Error");
    
    string non_existent_deposit = my_atm.make_deposit("9999", 100);
    REQUIRE(non_existent_deposit == "Error");

    string non_existent_withdrawal = my_atm.make_withdrawal("9999", 50);
    REQUIRE(non_existent_withdrawal == "Error");
}