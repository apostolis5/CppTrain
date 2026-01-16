#include "catch.hpp"
#include "bank_account.h"
#include <stdexcept>
#include <iostream>
#include <string> // Required for std::string
using namespace std;

TEST_CASE("BankAccount operations", "[account]") {
    BankAccount default_account("0000", "Default Account", 0);
    REQUIRE(default_account.get_balance() == 0);
    REQUIRE(default_account.get_accountId() == "0000"); 
    REQUIRE(default_account.get_accountUsername() == "Default Account");

    BankAccount account("1234", "Test Account", 4000);
    REQUIRE(account.get_balance() == 4000);
    REQUIRE(account.get_accountId() == "1234");
    REQUIRE(account.get_accountUsername() == "Test Account");

    account.deposit(300);
    REQUIRE(account.get_balance() == 4300);
    account.withdraw(500);
    REQUIRE(account.get_balance() == 3800);

    BankAccount NewAccount("5678", "Apostolis Account", 0);
    NewAccount.deposit(300);
    NewAccount.withdraw(200);
    REQUIRE(NewAccount.get_balance() == 100);
    REQUIRE(NewAccount.get_accountId() == "5678");
    REQUIRE(NewAccount.get_accountUsername() == "Apostolis Account");
}

TEST_CASE("Overdraft withdrawal throws an exception", "[account]") {
    BankAccount account("9876", "Overdraft Account", 500);
    REQUIRE_THROWS_AS(account.withdraw(510), std::runtime_error);
    REQUIRE(account.get_balance() == 500); // Balance should not change
}