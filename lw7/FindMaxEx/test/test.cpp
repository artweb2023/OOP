#define CATCH_CONFIG_MAIN

#include "../FindMaxEx/FindMaxEx.h"
#include "/OOP/catch2/catch.hpp"


struct Athlete
{
	std::string name;
	double height;
	double weight;
};


SCENARIO("Testing FindMax")
{
	GIVEN("Vector of integers")
	{
		std::vector<int> vec = { 4, 4, 1, 3, 23, 12 };

		WHEN("Finding the maximum value")
		{
			int maxValue;
			bool result = FindMaxEx(vec, maxValue, std::less<int>());

			THEN("The result should be true")
			{
				REQUIRE(result == true);
			}

			THEN("The maximum value should be 42")
			{
				REQUIRE(maxValue == 23);
			}
		}

		WHEN("Finding the maximum value in an empty vector")
		{
			std::vector<int> emptyVec;
			int maxValue;
			bool result = FindMaxEx(emptyVec, maxValue, std::less<int>());

			THEN("The result should be false")
			{
				REQUIRE(result == false);
			}
		}
	}

	GIVEN("Vector of athletes")
	{
		std::vector<Athlete> athletes = {
			{"Ivan Petrov", 180.5, 75.5},
			{"Peter Ivanov", 175.9, 65.5},
			{"Mike Sidorov", 190.2, 90.5},
			{"Anna Ziga", 170.4, 55.4}
		};

		WHEN("Finding the tallest athlete")
		{
			auto compareByHeight = [](const Athlete& a, const Athlete& b) {
				return a.height < b.height;
				};
			Athlete tallest;
			bool result = FindMaxEx(athletes, tallest, compareByHeight);

			THEN("The result should be true")
			{
				REQUIRE(result == true);
			}

			THEN("The tallest athlete should be Mike Sidorov")
			{
				REQUIRE(tallest.name == "Mike Sidorov");
				REQUIRE(tallest.height == 190.2);
			}
		}

		WHEN("Finding the heaviest athlete")
		{
			auto compareByWeight = [](const Athlete& a, const Athlete& b) {
				return a.weight < b.weight;
				};
			Athlete heaviest;
			bool result = FindMaxEx(athletes, heaviest, compareByWeight);

			THEN("The result should be true")
			{
				REQUIRE(result == true);
			}

			THEN("The heaviest athlete should be Mike Sidorov")
			{
				REQUIRE(heaviest.name == "Mike Sidorov");
				REQUIRE(heaviest.weight == 90.5);
			}
		}

		WHEN("Finding the tallest athlete in an empty vector")
		{
			std::vector<Athlete> emptyAthletes;
			auto compareByHeight = [](const Athlete& a, const Athlete& b) {
				return a.height < b.height;
				};
			Athlete tallest;
			bool result = FindMaxEx(emptyAthletes, tallest, compareByHeight);

			THEN("The result should be false")
			{
				REQUIRE(result == false);
			}
		}
	}
}