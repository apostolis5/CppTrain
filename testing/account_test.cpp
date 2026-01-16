#include "catch.hpp"
#include "bank_account.h"
#include <stdexcept>
#include <iostream>

using namespace std;

TEST_CASE("BankAccount operations", "[account]") {
    BankAccount default_account;
    REQUIRE(default_account.get_balance() == 0);
    BankAccount account(4000);
    REQUIRE(account.get_balance() == 4000);
    account.deposit(300);
    REQUIRE(account.get_balance() == 4300);
    account.withdraw(500);
    REQUIRE(account.get_balance() == 3800);

    BankAccount NewAccount;
    NewAccount.deposit(300);
    NewAccount.withdraw(200);
    REQUIRE(NewAccount.get_balance() == 100);
}

// This test case CHECKS FOR A FAILURE.
// It verifies that the BankAccount::withdraw function correctly
// throws an exception when a user tries to withdraw more money
// than the account holds. The test PASSES if the expected
// error (the exception) occurs.
TEST_CASE("Overdraft withdrawal throws an exception", "[account]") {
    BankAccount account(500);
    // This checks that calling withdraw with smaller available balance triggers error.
    // This is the correct way to test for error conditions.
    REQUIRE_THROWS_AS(account.withdraw(510), std::runtime_error);

    // We also check that the balance hasn't changed.
    REQUIRE(account.get_balance() == 500);
}