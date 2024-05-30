#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw6/SquareEquations/SquareEquations/Solve.h"

SCENARIO("Testing Solve function")
{
	GIVEN("Solve function")
	{
		WHEN("a is zero")
		{
			THEN("Check if invalid_argument is thrown")
			{
				REQUIRE_THROWS_AS(Solve(0, 2, 3), std::invalid_argument);
			}
		}
		WHEN("discriminant is negative")
		{
			THEN("Check if domain_error is thrown")
			{
				REQUIRE_THROWS_AS(Solve(1, 2, 3), std::domain_error);
			}
		}
		WHEN("discriminant is zero")
		{
			THEN("Check roots when discriminant is zero")
			{
				EquationRoots roots = Solve(1, 2, 1);
				REQUIRE(roots.numRoots == 1);
				REQUIRE(roots.roots[0] == Approx(-1));
			}
		}
		WHEN("discriminant is positive")
		{
			THEN("Check roots when discriminant is positive")
			{
				EquationRoots roots = Solve(1, -3, 2);
				REQUIRE(roots.numRoots == 2);
				REQUIRE(roots.roots[0] == Approx(2));
				REQUIRE(roots.roots[1] == Approx(1));
			}
		}
	}
}