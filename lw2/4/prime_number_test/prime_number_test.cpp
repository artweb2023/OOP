#define CATCH_CONFIG_MAIN
#ifdef NDEBUG
#endif

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw2/4/prime_numbers/ParseArgs.h"
#include "/OOP/lw2/4/prime_numbers/prime_number.h"
#include <boost/timer.hpp>


SCENARIO("Check function ParseArgs")
{
	GIVEN("Testing a function for incorrect value")
	{
		WHEN("ParseArgs is called with incorrect number of arguments")
		{
			char* argv[] = { const_cast<char*>("program") };
			int argc = 1;
			auto result = ParseArgs(argc, argv);
			THEN("It should return nullopt")
			{
				REQUIRE(result.has_value() == false);
			}
		}
		WHEN("ParseArgs is called with non-integer argument")
		{
			char* argv[] = { const_cast<char*>("program"), const_cast<char*>("abc") };
			int argc = 2;
			auto result = ParseArgs(argc, argv);
			THEN("It should return nullopt")
			{
				REQUIRE(result.has_value() == false);
			}
		}
		WHEN("ParseArgs is called with out-of-range argument")
		{
			char* argv[] = { const_cast <char*>("program"), const_cast <char*> ("1000000001") };
			int argc = 2;
			auto result = ParseArgs(argc, argv);
			THEN("It should return nullopt")
			{
				REQUIRE(result.has_value() == false);
			}
		}
		WHEN("ParseArgs is called with correct argument")
		{
			char* argv[] = { const_cast <char*> ("program_name"), const_cast <char*> ("100") };
			int argc = 2;
			auto result = ParseArgs(argc, argv);
			THEN("It should return the correct value")
			{
				REQUIRE(result.has_value());
				REQUIRE(result.value() == 100);
			}
		}
	}
}
// добавить дерективу которая будет запускать данный тест только в релизе
// добавить граничные кейсы для тестов!!

SCENARIO("Testing the execution time of a function for a value of 100 million")
{
	GIVEN("Testing a function for maximum quantity and execution time")
	{
		WHEN("GeneratePrimeNumbersSet is called")
		{
			boost::timer t;
			t.restart();
			std::set<int> primeNumbers = GeneratePrimeNumbersSet(100000000);
			double duration = t.elapsed();
			THEN("Checking quantity of prime numbers up to 100 million and time")
			{
				REQUIRE(primeNumbers.size() == 5761455);
				REQUIRE(duration <= 12.0);
			}
		}
	}
	GIVEN("Testing a function for upperBound = 1")
	{
		WHEN("GeneratePrimeNumbersSet is called")
		{
			std::set<int> primeNumbers = GeneratePrimeNumbersSet(1);
			THEN("Checking quantity of prime numbers up to 1 number")
			{
				REQUIRE(primeNumbers.size() == 0);
			}
		}
	}
	GIVEN("Testing a function for some number")
	{
		WHEN("GeneratePrimeNumbersSet is called")
		{
			std::set<int> primeNumbers = GeneratePrimeNumbersSet(7);
			THEN("Checking quantity ")
			{
				REQUIRE(primeNumbers.size() == 4);
				REQUIRE(primeNumbers.contains(2));
				REQUIRE(primeNumbers.contains(3));
				REQUIRE(primeNumbers.contains(5));
				REQUIRE(primeNumbers.contains(7));
			}
		}
	}
	GIVEN("Testing a function for some border test")
	{
		WHEN("GeneratePrimeNumbersSet is called")
		{
			std::set<int> primeNumbers = GeneratePrimeNumbersSet(9);
			THEN("Checking quantity ")
			{
				REQUIRE(primeNumbers.size() == 4);
				REQUIRE(primeNumbers.contains(2));
				REQUIRE(primeNumbers.contains(3));
				REQUIRE(primeNumbers.contains(5));
				REQUIRE(primeNumbers.contains(7));
			}
		}
	}
	GIVEN("Testing a function for some border test")
	{
		WHEN("GeneratePrimeNumbersSet is called")
		{
			std::set<int> primeNumbers = GeneratePrimeNumbersSet(18);
			THEN("Checking quantity ")
			{
				REQUIRE(primeNumbers.size() == 7);
				REQUIRE(primeNumbers.contains(2));
				REQUIRE(primeNumbers.contains(3));
				REQUIRE(primeNumbers.contains(5));
				REQUIRE(primeNumbers.contains(7));
				REQUIRE(primeNumbers.contains(11));
				REQUIRE(primeNumbers.contains(13));
				REQUIRE(primeNumbers.contains(17));
			}
		}
	}
}