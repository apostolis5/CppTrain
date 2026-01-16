#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> // Required for std::runtime_error
#include "atm.cpp" // Include the implementation file directly for testing private members if needed, or link appropriately
#include "bank_account.h"
using namespace std;

TEST_CASE("ATM manages multiple bank accounts", "[ATM]") {
    ATM my_atm;

    BankAccount acc1("1111", "Alice Smith", 100); // Changed to int
    BankAccount acc2("2222", "Bob Johnson", 500); // Changed to int

    my_atm.add_account(acc1);
    my_atm.add_account(acc2);

    SECTION("Accounts are added and retrievable") {
        REQUIRE(my_atm.find_account("1111") != nullptr);
        REQUIRE(my_atm.find_account("2222") != nullptr);
        REQUIRE(my_atm.find_account("3333") == nullptr); // Non-existent account
    }

    SECTION("Deposit to a specific account") {
        my_atm.make_deposit("1111", 50); // Changed to int
        REQUIRE(my_atm.find_account("1111")->get_balance() == 150);
        REQUIRE(my_atm.find_account("2222")->get_balance() == 500); // Other account unaffected
    }

    SECTION("Withdrawal from a specific account") {
        my_atm.make_withdrawal("2222", 100); // Changed to int
        REQUIRE(my_atm.find_account("2222")->get_balance() == 400);
        REQUIRE(my_atm.find_account("1111")->get_balance() == 100); // Other account unaffected
    }

    SECTION("Withdrawal with insufficient funds") {
        BankAccount* acc1_ptr = my_atm.find_account("1111");
        int initial_balance = acc1_ptr->get_balance(); // Changed to int
        
        // ATM::make_withdrawal calls BankAccount::withdraw, which throws the exception
        // We need to wrap the call that *might* throw in REQUIRE_THROWS_AS
        REQUIRE_THROWS_AS(acc1_ptr->withdraw(1000), std::runtime_error); 
        REQUIRE(acc1_ptr->get_balance() == initial_balance); // Balance should not change
    }

    SECTION("Operations on non-existent accounts") {
        // These operations should not crash and ideally report an error.
        // The output messages are checked implicitly by observing no crashes.
        my_atm.make_deposit("9999", 100); // Changed to int
        my_atm.make_withdrawal("8888", 50); // Changed to int
        // Balance of existing accounts should remain unchanged
        REQUIRE(my_atm.find_account("1111")->get_balance() == 100);
        REQUIRE(my_atm.find_account("2222")->get_balance() == 500);
    }
}