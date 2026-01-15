#include "catch.hpp"
#include "bank_account.h"

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
}