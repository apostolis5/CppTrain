#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else_if.h"
#include "switch.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test overtime function") {
	REQUIRE(overtime(30) == false);
	REQUIRE(overtime(40) == false);
	REQUIRE(overtime(41) == true);
}

TEST_CASE("Test get generation if else if function")
{
	REQUIRE(get_generation(1800) == "Invalid Year");
	REQUIRE(get_generation(1999) == "Centenial");
	REQUIRE(get_generation(1980) == "Millenial");
	REQUIRE(get_generation(1970) == "Generation X");
	REQUIRE(get_generation(1960) == "Baby Boomer");
	REQUIRE(get_generation(1930) == "Silent Generation");
	REQUIRE(get_generation(2023) == "Invalid Year");
}

TEST_CASE("Test switch menu function")
{
	REQUIRE(menu(0) == "Invalid Option");
	REQUIRE(menu(1) == "Option 1");
	REQUIRE(menu(2) == "Option 2");
	REQUIRE(menu(3) == "Option 3");
	REQUIRE(menu(4) == "Option 4");
	REQUIRE(menu(5) == "Invalid Option");
}


