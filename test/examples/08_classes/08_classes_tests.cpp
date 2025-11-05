#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"  // Include the header file for BankAccount class

using std::unique_ptr; using std::make_unique;
using namespace std;

TEST_CASE("Test BankAccount -> get_balance()")
{
	// Test the default constructor
	BankAccount default_account;
	REQUIRE(default_account.get_balance() == 0);

	// Test the parameterized constructor
	BankAccount account(500);
	REQUIRE(account.get_balance() == 500);
}