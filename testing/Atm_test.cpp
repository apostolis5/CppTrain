#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include <sstream> 
#include <optional> 
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
    REQUIRE(display_initial == "500"); 

    // 3. ATM deposits money
    string deposit_message = my_atm.make_deposit("1001", 100);
    REQUIRE(deposit_message == "200 OK"); 
    // We should verify the internal state of the BankInternalSystem to ensure the deposit actually happened.
    REQUIRE(internal_system.get_balance_for_customer("1001") == 600); 

    // 4. ATM displays updated balance
    string display_after_deposit = my_atm.display_balance("1001");
    REQUIRE(display_after_deposit == "600");

    // 5. ATM withdraws money
    string withdrawal_message = my_atm.make_withdrawal("1001", 150);
    REQUIRE(withdrawal_message == "200 OK"); 
    REQUIRE(internal_system.get_balance_for_customer("1001") == 450); 

    // 6. ATM displays final balance
    string display_final = my_atm.display_balance("1001");
    REQUIRE(display_final == "450"); 
}