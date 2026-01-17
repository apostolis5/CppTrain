#include "catch.hpp"
#include "bank_account.h"
#include "bank_internal_system.h"

TEST_CASE("BankAccount Registration Method", "[BankAccount]") {
    
    BankInternalSystem bankSystem;

    SECTION("Register With System") {
        // Create an object on the stack
        BankAccount acc1("001", "reg_user", 1500);
        
        // Test successful registration
        string result = acc1.register_to_system(bankSystem);
        REQUIRE(result == "200 OK");

        // Verify it's in the system
        BankAccount* system_copy = bankSystem.get_account_for_customer("001");
        REQUIRE(system_copy != nullptr);
        REQUIRE(system_copy->get_balance() == 1500);
        
        // Test registration of a duplicate account
        BankAccount acc2("001", "duplicate_user", 100);
        string result2 = acc2.register_to_system(bankSystem);
        REQUIRE(result2 == "Error");
    }
}
