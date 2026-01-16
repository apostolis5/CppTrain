#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include <sstream> 
#include <optional> 
#include "bank_internal_system.h" 
#include "bank_account.h"
using namespace std;

TEST_CASE("BankInternalSystem manages accounts", "[BankInternalSystem]") {
    // Each SECTION will have its own fresh BankInternalSystem instance

    SECTION("Account creation and retrieval") {
        BankInternalSystem bank_system;
        REQUIRE(bank_system.create_account("1111", "Alice Smith", 100) == "200 OK");
        REQUIRE(bank_system.create_account("2222", "Bob Johnson", 500) == "200 OK");

        REQUIRE(bank_system.get_account_for_customer("1111") != nullptr);
        REQUIRE(bank_system.get_account_for_customer("2222") != nullptr);
        REQUIRE(bank_system.get_account_for_customer("3333") == nullptr); // Non-existent
    }

    SECTION("Deposit to account") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        REQUIRE(bank_system.deposit_to_account("1111", 50) == "200 OK");
        REQUIRE(bank_system.get_balance_for_customer("1111") == 150);
    }

    SECTION("Withdraw from account") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        REQUIRE(bank_system.withdraw_from_account("1111", 50) == "200 OK");
        REQUIRE(bank_system.get_balance_for_customer("1111") == 50);
    }

    SECTION("Withdraw with insufficient funds") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        std::string message = bank_system.withdraw_from_account("1111", 150);
        REQUIRE(message == "Error");
        REQUIRE(bank_system.get_balance_for_customer("1111") == 100); // Balance should not change
    }

    SECTION("Delete account by ID") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        bank_system.create_account("2222", "Bob Johnson", 500);
        REQUIRE(bank_system.delete_account_by_id("1111") == "200 OK");
        REQUIRE(bank_system.get_account_for_customer("1111") == nullptr);
        REQUIRE(bank_system.get_account_for_customer("2222") != nullptr); // Other account unaffected
    }

    SECTION("Delete non-existent account by ID") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        std::string message = bank_system.delete_account_by_id("9999");
        REQUIRE(message == "Error");
        REQUIRE(bank_system.get_account_for_customer("1111") != nullptr); // Existing account unaffected
    }
}