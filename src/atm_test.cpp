#include "catch.hpp"
#include "bank_account.h"
#include "atm.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("ATM Encapsulation and Interaction", "[atm]") {
    BankAccount account(9000);
    ATM atm(account);

    SECTION("Deposit via ATM") {
        // Simulate user input "500"
        std::stringstream input("500");
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

        atm.make_deposit();

        std::cin.rdbuf(oldCin); // Restore cin

        REQUIRE(account.get_balance() == 9500);
    }

    SECTION("Withdrawal via ATM") {
        // Simulate user input "1000"
        std::stringstream input("1000");
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

        atm.make_withdrawal();

        std::cin.rdbuf(oldCin); // Restore cin

        REQUIRE(account.get_balance() == 8000);
    }
}