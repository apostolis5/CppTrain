#include "catch.hpp"
#include "bank_account.h"
#include "bank_internal_system.h"
#include <memory>

TEST_CASE("BankAccount Getters and Setters", "[BankAccount]") {
    
    SECTION("Getters and Setters") {
        auto acc1 = make_shared<BankAccount>("001", "test_user", 1500);
        
        REQUIRE(acc1->get_accountId() == "001");
        REQUIRE(acc1->get_accountUsername() == "test_user");
        REQUIRE(acc1->get_balance() == 1500);

        acc1->set_accountUsername("new_user");
        REQUIRE(acc1->get_accountUsername() == "new_user");
    }
}
