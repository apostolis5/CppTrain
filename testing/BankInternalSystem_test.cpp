#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include <sstream> 
#include <optional> 
#include "bank_internal_system.h" 
#include "bank_account.h"

TEST_CASE("BankInternalSystem manages accounts", "[BankInternalSystem]") {
    // Each SECTION will have its own fresh BankInternalSystem instance
    // This ensures that tests are independent and don't rely on state changes from other sections.

    SECTION("Account creation and retrieval") {
        BankInternalSystem bank_system;
        REQUIRE(bank_system.create_account("1111", "Alice Smith", 100).find("created successfully") != std::string::npos);
        REQUIRE(bank_system.create_account("2222", "Bob Johnson", 500).find("created successfully") != std::string::npos);

        REQUIRE(bank_system.get_account_for_customer("1111") != nullptr);
        REQUIRE(bank_system.get_account_for_customer("2222") != nullptr);
        REQUIRE(bank_system.get_account_for_customer("3333") == nullptr); // Non-existent
        REQUIRE(bank_system.get_account_for_customer("2222")->get_accountUsername() == "Bob Johnson");
    }

    SECTION("Duplicate account creation") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        // Attempt to create with same ID, should report error and not change state
        std::string message = bank_system.create_account("1111", "Alice Smith Duplicate", 200);
        REQUIRE(message.find("Error: Account with ID 1111 already exists.") != std::string::npos);
        REQUIRE(bank_system.get_balance_for_customer("1111") == 100); // Balance should remain 100
        REQUIRE(bank_system.get_account_for_customer("1111")->get_accountUsername() == "Alice Smith");
    }

    SECTION("Deposit to account") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        REQUIRE(bank_system.deposit_to_account("1111", 50).find("processed") != std::string::npos);
        REQUIRE(bank_system.get_balance_for_customer("1111") == 150);
    }

    SECTION("Withdraw from account") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        REQUIRE(bank_system.withdraw_from_account("1111", 50).find("processed") != std::string::npos);
        REQUIRE(bank_system.get_balance_for_customer("1111") == 50);
    }

    SECTION("Withdraw with insufficient funds") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        // Withdraw should return an error message
        std::string message = bank_system.withdraw_from_account("1111", 150);
        REQUIRE(message.find("Withdrawal failed for account 1111: Withdrawal amount exceeds balance.") != std::string::npos);
        REQUIRE(bank_system.get_balance_for_customer("1111") == 100); // Balance should not change
    }

    SECTION("Delete account by ID") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        bank_system.create_account("2222", "Bob Johnson", 500);
        REQUIRE(bank_system.delete_account_by_id("1111").find("deleted successfully") != std::string::npos);
        REQUIRE(bank_system.get_account_for_customer("1111") == nullptr);
        REQUIRE(bank_system.get_account_for_customer("2222") != nullptr); // Other account unaffected
    }

    SECTION("Delete non-existent account by ID") {
        BankInternalSystem bank_system;
        bank_system.create_account("1111", "Alice Smith", 100);
        std::string message = bank_system.delete_account_by_id("9999"); // Should return error message
        REQUIRE(message.find("Error: Account with ID 9999 not found.") != std::string::npos);
        REQUIRE(bank_system.get_account_for_customer("1111") != nullptr); // Existing account unaffected
    }

    SECTION("Get balance for non-existent account returns std::nullopt") {
        BankInternalSystem bank_system;
        REQUIRE(bank_system.get_balance_for_customer("9999") == std::nullopt);
    }
}