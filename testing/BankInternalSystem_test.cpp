#include "catch.hpp"
#include "bank_internal_system.h"
#include "bank_account.h"

TEST_CASE("BankInternalSystem Registration", "[BankInternalSystem]") {

    BankInternalSystem bankSystem;

    SECTION("Account Registration") {
        BankAccount acc1("001", "testuser1", 1000);
        
        // Test successful registration
        string result1 = bankSystem.register_account(acc1);
        REQUIRE(result1 == "200 OK");

        // Verify it's in the system
        BankAccount* system_copy = bankSystem.get_account_for_customer("001");
        REQUIRE(system_copy != nullptr);
        REQUIRE(system_copy->get_balance() == 1000);

        // Test registration of a duplicate account
        BankAccount acc2("001", "testuser2", 500);
        string result2 = bankSystem.register_account(acc2);
        REQUIRE(result2 == "Error");
    }
}
