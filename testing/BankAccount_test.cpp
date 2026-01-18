#include "catch.hpp"
#include "bank_account.h"
#include "bank_internal_system.h"
#include <memory>

TEST_CASE("BankAccount Getters and Setters", "[BankAccount]") {
    
    SECTION("Getters and Setters") {
        BankAccount* acc1 = new BankAccount("001", "work_account", 1000);
        
        REQUIRE(acc1->get_accountId() == "001");
        REQUIRE(acc1->get_accountUsername() == "work_account");
        REQUIRE(acc1->get_balance() == 1000);
        acc1->set_accountUsername("new_user");
        REQUIRE(acc1->get_accountUsername() == "new_user");

        acc1->deposit(500);
        REQUIRE(acc1->get_balance() == 1500);
        acc1->withdraw(500);
        REQUIRE(acc1->get_balance() == 1000);

        delete acc1;
    }
}
