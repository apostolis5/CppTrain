#include "catch.hpp"
#include "atm.h"
#include "bank_account.h"
#include "bank_internal_system.h"
#include <memory>

TEST_CASE("ATM Final Tests", "[ATM]") {

    BankInternalSystem internal_system;
    ATM atm(internal_system);

    SECTION("ATM transactions") {
        // Create and register accounts for testing
        auto acc1 = make_shared<BankAccount>("1001", "Customer A", 500);
        internal_system.register_account(acc1);

        auto acc2 = make_shared<BankAccount>("1002", "Customer B", 200);
        internal_system.register_account(acc2);

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

        SECTION("ATM multiple accounts transactions") {
            // Initialize bank system
            BankInternalSystem bankSystem;
            auto piraeusAtm = make_unique<ATM>(bankSystem);

            auto acc1 = make_shared<BankAccount>("001", "work_account", 5000);
            auto acc2 = make_shared<BankAccount>("002", "personal_account", 3000);
            auto acc3 = make_shared<BankAccount>("003", "savings_account", 10000);
            // make accounts available both in the banking system and atm
            bankSystem.register_account(acc1);
            bankSystem.register_account(acc2);
            bankSystem.register_account(acc3);


            // Modify Accounts through ATM Interface
            string id3 = acc3->get_accountId();   
            piraeusAtm->make_deposit(id3, 2000);
            piraeusAtm->make_withdrawal(id3, 1000);
            //std::cout << "Balance after ATM operations: " << piraeusAtm->display_balance(id3) << std::endl;
            REQUIRE(piraeusAtm->display_balance(id3) == "11000");
        }
}
