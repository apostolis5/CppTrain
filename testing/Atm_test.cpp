#include <catch.hpp>
#include <string>
#include <vector>
#include <stdexcept> 
#include "atm.cpp" 
#include "bank_account.h"
using namespace std;

TEST_CASE("ATM manages multiple bank accounts", "[ATM]") {
    ATM my_atm;

    BankAccount acc1("1111", "Alice Smith", 100); 
    BankAccount acc2("2222", "Bob Johnson", 500); 

    my_atm.add_account(acc1);
    my_atm.add_account(acc2);

    SECTION("Accounts are added and retrievable") {
        REQUIRE(my_atm.find_account("1111") != nullptr);
        REQUIRE(my_atm.find_account("2222") != nullptr);
        REQUIRE(my_atm.find_account("3333") == nullptr); // Non-existent account
    }

    SECTION("Deposit to a specific account") {
        my_atm.make_deposit("1111", 50); 
        REQUIRE(my_atm.find_account("1111")->get_balance() == 150);
        REQUIRE(my_atm.find_account("2222")->get_balance() == 500); // Other account unaffected
    }

    SECTION("Withdrawal from a specific account") {
        my_atm.make_withdrawal("2222", 100);
        REQUIRE(my_atm.find_account("2222")->get_balance() == 400);
        REQUIRE(my_atm.find_account("1111")->get_balance() == 100); // Other account unaffected
    }

    SECTION("Withdrawal with insufficient funds") {
        BankAccount* acc1_ptr = my_atm.find_account("1111");
        int initial_balance = acc1_ptr->get_balance(); 
        
        REQUIRE_THROWS_AS(acc1_ptr->withdraw(1000), std::runtime_error); 
        REQUIRE(acc1_ptr->get_balance() == initial_balance); // Balance should not change
    }

    SECTION("Operations on non-existent accounts") {
        my_atm.make_deposit("9999", 100); 
        my_atm.make_withdrawal("8888", 50);
        // Balance of existing accounts should remain unchanged
        REQUIRE(my_atm.find_account("1111")->get_balance() == 100);
        REQUIRE(my_atm.find_account("2222")->get_balance() == 500);
    }
}