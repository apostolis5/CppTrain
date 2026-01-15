#include "catch.hpp"
#include "bank_account.h"
#include "atm.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("ATM Vector of Accounts", "[vector]") {
    ATM multiAccountATM;

    SECTION("Initial state is empty") {
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        
        multiAccountATM.display_accounts();
        
        std::cout.rdbuf(oldCout);
        REQUIRE(buffer.str().empty());
    }

    SECTION("Adding accounts works correctly") {
        BankAccount a1(100);
        BankAccount a2(200);

        multiAccountATM.add_account(a1);
        multiAccountATM.add_account(a2);

        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        multiAccountATM.display_accounts();
        std::cout.rdbuf(oldCout);

        std::string output = buffer.str();
        REQUIRE(output.find("Saved Account 0 Balance: 100") != std::string::npos);
        REQUIRE(output.find("Saved Account 1 Balance: 200") != std::string::npos);
    }
}