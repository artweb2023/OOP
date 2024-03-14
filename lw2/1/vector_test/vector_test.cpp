#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw2/1/vector/ProcessVector.h"
#include <iostream>


SCENARIO("Data can be read from input stream")
{
	GIVEN("An input stream with empty")
	{
		std::istringstream input("");
		std::vector<double> expected;
		WHEN("GetVector is called")
		{
			auto numbers = GetVector(input);
			THEN("Empty numbers")
			{
				REQUIRE(numbers == expected);
			}
		}
	}
	GIVEN("An input stream with some numbers")
	{
		std::istringstream input("3.14 2.718 1.618");
		std::vector<double> expected = { 3.14 ,2.718, 1.618 };
		WHEN("GetVector is called")
		{
			auto numbers = GetVector(input);
			THEN("Numbers are read correctly")
			{
				REQUIRE(numbers == expected);
			}
		}
	}
	GIVEN("An input stream with some invalid value")
	{
		std::istringstream input("3.14 b 1.618");
		WHEN("GetVector is called") {
			THEN("An exception is thrown") {
				REQUIRE_THROWS_AS(GetVector(input), std::runtime_error);
			}
		}
	}
}

SCENARIO("Vector can be processed by multiplying each element with the minimum element")
{
	std::vector<double> original = { 2.00 , 3.00 , 4.00 };
	GIVEN("A vector with some items")
	{
		std::vector<double> result = { 4.00 , 6.00 , 8.00 };
		WHEN("MultiplyOnMinimumVectorElement is called")
		{
			MultiplyOnMinimumVectorElement(original);
			THEN("Checking the result")
			{
				REQUIRE(original == result);
			}
		}
	}
	GIVEN("A vector is empty")
	{
		std::vector<double> emptyVector;
		std::vector<double> result;
		WHEN("MultiplyOnMinimumVectorElement is called")
		{
			MultiplyOnMinimumVectorElement(emptyVector);
			THEN("Checking the result")
			{
				REQUIRE(result == emptyVector);
			}
		}
	}
}