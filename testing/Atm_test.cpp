#include "catch.hpp"
#include "atm.h"
#include "bank_account.h"
#include "bank_internal_system.h"
#include <memory>

TEST_CASE("ATM Final Tests", "[ATM]") {

    BankInternalSystem bankSystem;
    ATM* atm = new ATM(bankSystem); 

    SECTION("ATM transactions") {
    // Create and register accounts for testing
    BankAccount* acc1 = new BankAccount("1001", "work_account", 500);
    BankAccount* acc2 = new BankAccount("1002", "personal_account", 200);
    bankSystem.register_account(shared_ptr<BankAccount>(acc1));
    bankSystem.register_account(shared_ptr<BankAccount>(acc2));
    
        // ATM user operations
        REQUIRE(atm->display_balance("1001") == "500");
        REQUIRE(atm->display_balance("1002") == "200");
        REQUIRE(atm->display_balance("9999") == "Error");
        // Test make_deposit
        REQUIRE(atm->make_deposit("1001", 100) == "200 OK");
        REQUIRE(atm->display_balance("1001") == "600");
        // Test make_withdrawal
        REQUIRE(atm->make_withdrawal("1002", 50) == "200 OK");
        REQUIRE(atm->display_balance("1002") == "150");
        
        // Test BankAccount Objetcs directly
        REQUIRE(acc1->get_balance() == 600);
        REQUIRE(acc2->get_balance() == 150);
        REQUIRE(acc2->get_accountUsername() == "personal_account");

        // Test BankAccount through BankInternalSystem
        REQUIRE(bankSystem.get_balance_for_accountID("1001") == 600);
        REQUIRE(bankSystem.get_balance_for_accountID("1002") == 150);
        REQUIRE(bankSystem.get_balance_for_accountID("9999") == -1);
    }
}
