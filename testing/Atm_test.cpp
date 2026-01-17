#include "catch.hpp"
#include "atm.h"
#include "bank_account.h"
#include "bank_internal_system.h"

TEST_CASE("ATM Final Tests", "[ATM]") {

    BankInternalSystem internal_system;
    ATM atm(internal_system);

    SECTION("ATM transactions") {
        // Create and register accounts for testing
        BankAccount acc1("1001", "Customer A", 500);
        acc1.register_to_system(internal_system);

        BankAccount acc2("1002", "Customer B", 200);
        acc2.register_to_system(internal_system);

        // Test display_balance
        REQUIRE(atm.display_balance("1001") == "500");
        REQUIRE(atm.display_balance("1002") == "200");
        REQUIRE(atm.display_balance("9999") == "Error");

        // Test make_deposit
        REQUIRE(atm.make_deposit("1001", 100) == "200 OK");
        REQUIRE(atm.display_balance("1001") == "600");

        // Test make_withdrawal
        REQUIRE(atm.make_withdrawal("1002", 50) == "200 OK");
        REQUIRE(atm.display_balance("1002") == "150");
    }
}
