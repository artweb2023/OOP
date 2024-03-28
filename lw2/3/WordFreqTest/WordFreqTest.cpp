#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw2/3/WordFreq/WordFreq.h"

SCENARIO("Check wordFreq")
{
	GIVEN("Testing a function for incorrect value")
	{
		std::istringstream input("4 5 6 & # $");
		WordFreq wordFreq;
		WHEN("ReadFromInputStream is called")
		{
			ReadFromInputStream(input, wordFreq);
			THEN("Check if words are correctly added to map")
			{
				REQUIRE(wordFreq.size() == 0);
			}
		}
	}
	GIVEN("Testing a function with different letter cases")
	{
		std::istringstream input("HeLLo hello HeLlO");
		WordFreq wordFreq;
		WHEN("ReadFromInputStream is called")
		{
			ReadFromInputStream(input, wordFreq);
			THEN("Check correct add word and freq")
			{
				REQUIRE(wordFreq == WordFreq{ {"hello", 3} });
			}
		}
	}
	GIVEN("Empty input")
	{
		std::istringstream input("");
		WordFreq wordFreq;
		WHEN("ReadFromInputStream is called")
		{
			ReadFromInputStream(input, wordFreq);
			THEN("Check if wordFreq is empty")
			{
				REQUIRE(wordFreq.empty());
			}
		}
	}
	GIVEN("Input with repeated words")
	{
		std::istringstream input("apple apple banana banana");
		WordFreq wordFreq;
		WHEN("ReadFromInputStream is called")
		{
			ReadFromInputStream(input, wordFreq);
			THEN("Check if wordFreq contains correct frequencies")
			{
				REQUIRE(wordFreq == WordFreq{ {"apple", 2}, {"banana", 2} });
			}
		}
	}
	GIVEN("Input with special characters")
	{
		std::istringstream input("apple! banana#");
		WordFreq wordFreq;
		WHEN("ReadFromInputStream is called")
		{
			ReadFromInputStream(input, wordFreq);
			THEN("Check if wordFreq does not contain special characters")
			{
				REQUIRE(wordFreq == WordFreq{ {"apple", 1}, {"banana", 1} });
			}
		}
	}
}