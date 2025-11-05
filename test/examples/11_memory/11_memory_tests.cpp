#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ref_pointers.h"
#include "my_vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
/*
TEST_CASE("Test reference and pointer parameters")
{
	int num1 = 1, num2 = 2;
	ref_ptr_params(num1, &num2);

	REQUIRE(num1 == 5);
	REQUIRE(num2 == 10);
}

TEST_CASE("Test my vector size")
{
	Vector v(3);
	REQUIRE(v.Size() == 0);
}

TEST_CASE("Test my vector capacity")
{
	Vector v(3);
	REQUIRE(v.Capacity() == 3 );
}

TEST_CASE("Test my vector class copy")
{
	Vector v1(3);
	Vector v2 = v1;
	v1[0] = 5;
	v2[0] = 10;

	REQUIRE(v1.Size() == v2.Size());
	REQUIRE(v1.Capacity() == v2.Capacity());

	REQUIRE(v1[0] != v2[0]);
}

TEST_CASE("Test my vector overwrite existing v2 with v1")
{
	Vector v1(3);
	Vector v2(3);
	v2 = v1;

}

TEST_CASE("Test moving v1 into v2")
{
	Vector v1(3);
	Vector v2 = std::move(v1);
}

TEST_CASE("Overwrite existing vector v1 with a value return function")
{
	Vector v1(3);
	v1 = get_vector();
}

TEST_CASE("Test vector push back with empty vector")
{
	Vector v;

	REQUIRE(v.Capacity() == 0);
	REQUIRE(v.Size() == 0);

	v.PushBack(5);

	REQUIRE(v.Capacity() == 8);
	REQUIRE(v.Size() == 1);
	REQUIRE(v[0] == 5);
}

TEST_CASE("Test vector push back with vector capacity 3")
{
	Vector v(3);

	REQUIRE(v.Capacity() == 3);
	REQUIRE(v.Size() == 0);

	v.PushBack(5);

	REQUIRE(v.Capacity() == 3);
	REQUIRE(v.Size() == 1);
	REQUIRE(v[0] == 5);

	v.PushBack(7);
	v.PushBack(10);
	v.PushBack(1);

	REQUIRE(v.Capacity() == 6);
	REQUIRE(v.Size() == 4);
	REQUIRE(v[0] == 5);
	REQUIRE(v[1] == 7);
}*/