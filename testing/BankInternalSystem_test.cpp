#include "catch.hpp"
#include "bank_internal_system.h"
#include "bank_account.h"
#include <memory>
using namespace std;

TEST_CASE("BankInternalSystem Registration", "[BankInternalSystem]") {

    BankInternalSystem bankSystem;

    SECTION("Account Registration") {
        auto acc1 = make_shared<BankAccount>("001", "testuser1", 1000);
        
        // Test successful registration
        string result1 = bankSystem.register_account(acc1);
        REQUIRE(result1 == "200 OK");

        // Verify it's in the system
        auto system_copy = bankSystem.get_account_for_customer("001");
        REQUIRE(system_copy != nullptr);
        REQUIRE(system_copy->get_balance() == 1000);

        // Test registration of a duplicate account
        auto acc2 = make_shared<BankAccount>("001", "testuser2", 500);
        string result2 = bankSystem.register_account(acc2);
        REQUIRE(result2 == "Error");
    }

    SECTION("Multiple Account Registrations") {
        BankInternalSystem bankSystem;

        auto acc1 = make_shared<BankAccount>("001", "work_account", 5000);
        auto acc2 = make_shared<BankAccount>("002", "personal_account", 3000);
        auto acc3 = make_shared<BankAccount>("003", "savings_account", 10000);
        // make accounts available in the banking system 
        bankSystem.register_account(acc1);
        bankSystem.register_account(acc2);
        bankSystem.register_account(acc3);


        // Modify Accounts through bank system directly (Clerk operations) 
        string id2 = acc2->get_accountId();
        bankSystem.deposit_to_account(id2, 2000);
        cout << "Balance after deposit: " << bankSystem.get_balance_for_accountID(id2) << endl;
        bankSystem.withdraw_from_account(id2, 1000);
        REQUIRE(bankSystem.get_balance_for_accountID(id2) == 4000);
        // Tests for delete acc3
        string accountId = acc3->get_accountId();
        bankSystem.delete_account(accountId);
        
        REQUIRE(bankSystem.get_account_for_customer(accountId) == nullptr);
        REQUIRE(bankSystem.get_all_accountsData().size() == 2);
        REQUIRE(bankSystem.get_balance_for_accountID(accountId) == -1);

        // Tests for edit acc2 username
        //string id2 = acc2->get_accountId();
        string new_username = "Personal_Account_Updated";
        bankSystem.edit_account_username(id2, new_username);
        REQUIRE(acc2->get_accountUsername() == new_username);
        REQUIRE(bankSystem.get_account_for_customer(id2)->get_accountUsername() == new_username);
        // acc2 balance should remain unchanged
        REQUIRE(bankSystem.get_balance_for_accountID(id2) == 4000);
        REQUIRE(acc2->get_balance()== 4000);
    }
}
