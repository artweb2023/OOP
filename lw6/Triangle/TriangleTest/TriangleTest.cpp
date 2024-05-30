#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw6/Triangle/Triangle/CTriangle.h"

SCENARIO("Testing CTriangle")
{
	GIVEN("CTriangle")
	{
		WHEN("Creating class CTriangle")
		{
			CTriangle triangle(3, 4, 5);
			THEN("Check Side")
			{
				REQUIRE(triangle.GetSide1() == 3);
				REQUIRE(triangle.GetSide2() == 4);
				REQUIRE(triangle.GetSide3() == 5);
			}
			THEN("Check Perimeter")
			{
				REQUIRE(triangle.GetPerimeter() == Approx(12).epsilon(0.01));
			}
			THEN("Check Area")
			{
				REQUIRE(triangle.GetArea() == Approx(6).epsilon(0.01));
			}
		}
		WHEN("Creating class CTriangle with negative side")
		{
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(CTriangle(-1, 2, 3), std::invalid_argument);
				REQUIRE_THROWS_AS(CTriangle(1, -2, 3), std::invalid_argument);
				REQUIRE_THROWS_AS(CTriangle(1, 2, -3), std::invalid_argument);
			}
		}
		WHEN("Creating class CTriangle with invalid sides")
		{
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(CTriangle(1, 1, 3), std::domain_error);
				REQUIRE_THROWS_AS(CTriangle(1, 3, 1), std::domain_error);
				REQUIRE_THROWS_AS(CTriangle(3, 1, 1), std::domain_error);
			}
		}
		WHEN("Creating class CTriangle with zero side")
		{
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(CTriangle(0, 2, 3), std::domain_error);
				REQUIRE_THROWS_AS(CTriangle(1, 0, 3), std::domain_error);
				REQUIRE_THROWS_AS(CTriangle(1, 2, 0), std::domain_error);
			}
		}
	}
}