#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"
#include "decimals.h"
#include "char.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

/*test case echo_variable */
TEST_CASE("Test echo variable function", "make sure function returns the function argument value ") {
	REQUIRE(echo_number(5) == 5);
	REQUIRE(echo_number(6) == 6);
}


/*test case add_to_double_1 with 0 as parameter*/
TEST_CASE("Test decimal precision w add_to_double_1 function", "TEST that 0 + .3 + .3 +.3 = .9 ") {
	//REQUIRE(add_to_double_1(0) == .9);

}

/*test case add_to_double_1 with 1 as parameter*/
TEST_CASE("Test decimal precision w 1 add_to_double_1 function", "TEST that 1 + .3 + .3 +.3 = 1.9 ") {
	//REQUIRE(add_to_double_1(1) == 1.9);

}

/*test case add_to_double_2 with 0 as parameter*/
TEST_CASE("Test decimal precision w add_to_double_2 function", "TEST that 0 + .3 + .3 +.3 +.3+.3= 1.5 ") {
	REQUIRE(add_to_double_2(0) == 1.5);

}




/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */
TEST_CASE("Test convert char to int is ASCII value")
{
	REQUIRE(get_char_ascii_value('A') == 65);
}

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/
TEST_CASE("Test convert char to int is ASCII value for J o e")
{
	REQUIRE(get_char_ascii_value('J') == 74);
	REQUIRE(get_char_ascii_value('o') == 111);
	REQUIRE(get_char_ascii_value('e') == 101);
}

