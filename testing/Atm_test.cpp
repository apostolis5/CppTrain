#include "catch.hpp"
#include "bank_account.h"
#include "atm.cpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("ATM Encapsulation and Interaction", "[atm]") {
    BankAccount account(9000);
    ATM atm(account);

    atm.make_deposit(500);
    REQUIRE(account.get_balance() == 9500);
    
    atm.make_withdrawal(1000);
    REQUIRE(account.get_balance() == 8500);
}