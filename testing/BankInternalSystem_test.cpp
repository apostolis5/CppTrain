#include "catch.hpp"
#include "bank_internal_system.h"
#include "bank_account.h"
#include <memory>
using namespace std;

TEST_CASE("BankInternalSystem Registration", "[BankInternalSystem]") {

    BankInternalSystem bankSystem;

    SECTION("Account Registration") {
        BankAccount* acc1 = new BankAccount("001", "work_account", 1000);
        bankSystem.register_account(shared_ptr<BankAccount>(acc1));

        // Verify it's in the system
        shared_ptr<BankAccount> system_copy = bankSystem.get_account_for_customer("001");
        REQUIRE(system_copy != nullptr);
        REQUIRE(bankSystem.get_balance_for_accountID("001") == 1000);

        // Test registration of a duplicate account
        auto acc2 = make_shared<BankAccount>("001", "testuser2", 500);
        string result2 = bankSystem.register_account(acc2);
        REQUIRE(result2 == "Error");
    }

    SECTION("Multiple Account Modifications ") {
        BankInternalSystem bankSystem;

        BankAccount* acc1 = new BankAccount("001", "work_account", 1000);
        BankAccount* acc2 = new BankAccount("002", "personal_account", 3000);
        BankAccount* acc3 = new BankAccount("003", "savings_account", 10000);
        // make accounts available in the banking system 
        bankSystem.register_account(shared_ptr<BankAccount>(acc1));
        bankSystem.register_account(shared_ptr<BankAccount>(acc2));
        bankSystem.register_account(shared_ptr<BankAccount>(acc3));


        // Modify Accounts through bank system directly (Clerk operations) 
        string id2 = acc2->get_accountId();
        bankSystem.deposit_to_account(id2, 2000);
        cout << "Balance after deposit: " << bankSystem.get_balance_for_accountID(id2) << endl;
        bankSystem.withdraw_from_account(id2, 1000);
        REQUIRE(bankSystem.get_balance_for_accountID(id2) == 4000);
        REQUIRE(acc2->get_balance() == 4000);
        // Tests for delete acc3
        string id3 = acc3->get_accountId();
        bankSystem.delete_account(id3);

        REQUIRE(bankSystem.get_account_for_customer(id3) == nullptr);
        REQUIRE(bankSystem.get_all_accountsData().size() == 2);
        REQUIRE(bankSystem.get_balance_for_accountID(id3) == -1);

        // Tests for edit acc2 username
        //string id2 = acc2->get_accountId();
        string new_username = "New Username Inserted";
        bankSystem.edit_account_username(id2, new_username);
        REQUIRE(acc2->get_accountUsername() == new_username);
        REQUIRE(bankSystem.get_account_for_customer(id2)->get_accountUsername() == new_username);
        cout << "New username for account acc2 : " << acc2->get_accountUsername() << endl;
        // acc2 balance should remain unchanged
        REQUIRE(bankSystem.get_balance_for_accountID(id2) == 4000);
        REQUIRE(acc2->get_balance()== 4000);
    }
}
