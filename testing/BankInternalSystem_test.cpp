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

    SECTION("Multiple Account Registrations") {
        BankInternalSystem bankSystem;

        BankAccount* acc1 = new BankAccount("001", "work_account", 5000);
        BankAccount* acc2 = new BankAccount("002", "personal_account", 3000);
        BankAccount* acc3 = new BankAccount("003", "savings_account", 10000);
        // make accounts available both in the banking system 
        acc1->register_to_system(bankSystem);
        acc2->register_to_system(bankSystem);
        acc3->register_to_system(bankSystem);


        // Modify Accounts through bank system directly (Clerk operations) 
        string id2 = acc2->get_accountId();
        bankSystem.deposit_to_account(id2, 2000);
        cout << "Balance after deposit: " << bankSystem.get_balance_for_accountID(id2) << endl;
        bankSystem.withdraw_from_account(id2, 1000);
        REQUIRE(bankSystem.get_balance_for_accountID(id2) == 4000);
    }
}
