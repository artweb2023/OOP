#define CATCH_CONFIG_MAIN
#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw3/1.3/Rectangle/CRectangle.h"

SCENARIO("Test CRectangle")
{
	GIVEN("A rectangle with initial parameters")
	{
		Point initialPoint = { 0, 0 };
		int initialWidth = 5;
		int initialHeight = 10;
		CRectangle rectangle(initialPoint, initialWidth, initialHeight);
		REQUIRE(rectangle.GetLeftTop().x == 0);
		REQUIRE(rectangle.GetLeftTop().y == 0);
		REQUIRE(rectangle.GetRightBottom().x == 5);
		REQUIRE(rectangle.GetRightBottom().y == 10);
		REQUIRE(rectangle.GetWidth() == 5);
		REQUIRE(rectangle.GetHeight() == 10);
		REQUIRE(rectangle.GetArea() == 50);
		REQUIRE(rectangle.GetPerimeter() == 30);
		WHEN("Moving the rectangle")
		{
			rectangle.Move(2, 3);
			THEN("Check if coordinates are updated correctly")
			{
				REQUIRE(rectangle.GetLeftTop().x == 2);
				REQUIRE(rectangle.GetLeftTop().y == 3);
				REQUIRE(rectangle.GetRightBottom().x == 7);
				REQUIRE(rectangle.GetRightBottom().y == 13);
			}
		}
		WHEN("Scaling the rectangle")
		{
			rectangle.Scale(2, 3);
			THEN("Check if width and height are updated correctly")
			{
				REQUIRE(rectangle.GetWidth() == 10);
				REQUIRE(rectangle.GetHeight() == 30);
			}
		}
		WHEN("Intersecting with another rectangle")
		{
			Point otherPoint = { 3, 4 };
			int otherWidth = 5;
			int otherHeight = 5;
			CRectangle otherRectangle(otherPoint, otherWidth, otherHeight);
			THEN("Check if intersection works correctly")
			{
				REQUIRE(rectangle.Intersect(otherRectangle) == true);
				REQUIRE(rectangle.GetWidth() == 2);
				REQUIRE(rectangle.GetHeight() == 5);
			}
		}
	}
}