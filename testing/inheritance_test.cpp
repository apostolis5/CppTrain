#include "catch.hpp"
#include "checking_account.h"
#include "atm.h"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("Inheritance with CheckingAccount", "[inheritance]") {
    CheckingAccount check1;
    REQUIRE(check1.get_balance() == 0); // Default constructor

    check1.deposit(500);
    REQUIRE(check1.get_balance() == 500);

    // Test polymorphism via ATM
    ATM atm(check1);
    
    // Simulate deposit "200"
    std::stringstream input("200");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    
    atm.make_deposit();
    
    std::cin.rdbuf(oldCin);
    
    REQUIRE(check1.get_balance() == 700);
}