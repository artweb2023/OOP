#define CATCH_CONFIG_MAIN
#define _USE_MATH_DEFINES

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw4/Shapes/CCircle.h"
#include "/OOP/lw4/Shapes/CLineSegment.h"
#include "/OOP/lw4/Shapes/CPoint.h"
#include "/OOP/lw4/Shapes/CRectangle.h"
#include "/OOP/lw4/Shapes/ShapeCreator.h"
#include "/OOP/lw4/Shapes/ÑTriangle.h"
#include "fakeit.hpp"


SCENARIO("test Points")
{
	GIVEN("Points")
	{
		CPoint p1(1.0, 1.0);
		CPoint p2(2.0, 2.0);
		CPoint p3(10.0, -2.0);
		WHEN("Getting coordinates")
		{
			THEN("Coordinates are correct")
			{
				REQUIRE(p1.GetX() == 1.0);
				REQUIRE(p1.GetY() == 1.0);
				REQUIRE(p2.GetX() == 2.0);
				REQUIRE(p2.GetY() == 2.0);
				REQUIRE(p3.GetX() == 10.0);
				REQUIRE(p3.GetY() == -2.0);
			}
		}
		WHEN("Converting to string")
		{
			THEN("String representation is correct")
			{
				REQUIRE(p1.ToString() == "(1.00, 1.00)");
				REQUIRE(p2.ToString() == "(2.00, 2.00)");
				REQUIRE(p3.ToString() == "(10.00, -2.00)");
			}
		}
	}
}

SCENARIO("test Lines")
{
	GIVEN("Lines")
	{
		CPoint p1(1.0, 1.0);
		CPoint p2(2.0, 2.0);
		WHEN("Create Lines")
		{
			CLineSegment line(p1, p2, 0xFF0000);
			THEN("Properties are correct")
			{
				REQUIRE(line.GetStartPoint().GetX() == 1.0);
				REQUIRE(line.GetStartPoint().GetY() == 1.0);
				REQUIRE(line.GetEndPoint().GetX() == 2.0);
				REQUIRE(line.GetEndPoint().GetY() == 2.0);
				REQUIRE(line.GetOutlineColor() == 0xFF0000);
			}
			THEN("Perimeter is correct")
			{
				double expectedPerimeter = sqrt(pow(2.0 - 1.0, 2) + pow(2.0 - 1.0, 2));
				REQUIRE(line.GetPerimeter() == expectedPerimeter);
			}
			THEN("Area is zero")
			{
				REQUIRE(line.GetArea() == 0.0);
			}
			THEN("String representation is correct")
			{
				std::string expectedString = "Line: (1.00, 1.00) (2.00, 2.00) area 0.00 perimeter 1.41 length 1.41 outline ff0000";
				REQUIRE(line.ToString() == expectedString);
			}
		}
	}
}

SCENARIO("test Circles")
{
	GIVEN("Circles")
	{
		CPoint p1(1.0, 1.0);
		CPoint p3(10.0, -2.0);
		WHEN("Create Circle")
		{
			CCircle circ1(p1, 10, 0xFF0434, 0xF71435);
			CCircle circ2(p3, -5, 0xFF0000, 0xF75394);
			THEN("Check color")
			{
				REQUIRE(circ1.GetOutlineColor() == 0xFF0434);
				REQUIRE(circ1.GetFillColor() == 0xF71435);
				REQUIRE(circ2.GetOutlineColor() == 0xFF0000);
				REQUIRE(circ2.GetFillColor() == 0xF75394);
			}
			THEN("Check radius")
			{
				REQUIRE(circ1.GetRadius() == 10);
				REQUIRE(circ2.GetRadius() == 5);
			}
			THEN("Check origin")
			{
				CPoint origin1 = circ1.GetOrigin();
				CPoint origin2 = circ2.GetOrigin();
				REQUIRE(origin1.GetX() == 1.0);
				REQUIRE(origin1.GetY() == 1.0);
				REQUIRE(origin2.GetX() == 10.0);
				REQUIRE(origin2.GetY() == -2.0);
			}
			THEN("Check perimeter")
			{
				REQUIRE(circ1.GetPerimeter() == 2 * circ1.GetRadius() * M_PI);
				REQUIRE(circ2.GetPerimeter() == 2 * circ2.GetRadius() * M_PI);
			}
			THEN("Check area")
			{
				REQUIRE(circ1.GetArea() == circ1.GetRadius() * circ1.GetRadius() * M_PI);
				REQUIRE(circ2.GetArea() == circ2.GetRadius() * circ2.GetRadius() * M_PI);
			}
		}
	}
}

SCENARIO("test Rectangle")
{
	GIVEN("Rectangle")
	{
		CPoint leftTop(1.0, 4.0);
		CPoint rightBottom(5.0, 1.0);
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);
		WHEN("Getting properties")
		{
			THEN("Properties are correct")
			{
				REQUIRE(rectangle.GetLeftTop().GetX() == 1.0);
				REQUIRE(rectangle.GetLeftTop().GetY() == 4.0);
				REQUIRE(rectangle.GetRightBottom().GetX() == 5.0);
				REQUIRE(rectangle.GetRightBottom().GetY() == 1.0);
				REQUIRE(rectangle.GetOutlineColor() == outlineColor);
				REQUIRE(rectangle.GetFillColor() == fillColor);
			}
		}
		WHEN("Calculating perimeter")
		{
			THEN("Perimeter is correct")
			{
				double expectedPerimeter = (5.0 - 1.0 + 4.0 - 1.0) * 2;
				REQUIRE(rectangle.GetPerimeter() == expectedPerimeter);
			}
		}
		WHEN("Calculating area")
		{
			THEN("Area is correct")
			{
				double expectedArea = (5.0 - 1.0) * (4.0 - 1.0);
				REQUIRE(rectangle.GetArea() == expectedArea);
			}
		}
		WHEN("Converting to string")
		{
			THEN("String representation is correct")
			{
				std::string expectedString = "Rectangle: (1.00, 4.00) (5.00, 1.00) area 12.00 perimeter 14.00 outline ff0000 fill ff00";
				REQUIRE(rectangle.ToString() == expectedString);
			}
		}
	}
}

SCENARIO("test Triangle")
{
	GIVEN("Triangle")
	{
		CPoint vertex1(0.0, 0.0);
		CPoint vertex2(3.0, 0.0);
		CPoint vertex3(0.0, 4.0);
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
		WHEN("Getting properties")
		{
			THEN("Properties are correct")
			{
				REQUIRE(triangle.GetVertex1().GetX() == 0.0);
				REQUIRE(triangle.GetVertex1().GetY() == 0.0);
				REQUIRE(triangle.GetVertex2().GetX() == 3.0);
				REQUIRE(triangle.GetVertex2().GetY() == 0.0);
				REQUIRE(triangle.GetVertex3().GetX() == 0.0);
				REQUIRE(triangle.GetVertex3().GetY() == 4.0);
				REQUIRE(triangle.GetOutlineColor() == outlineColor);
				REQUIRE(triangle.GetFillColor() == fillColor);
			}
		}
		WHEN("Calculating perimeter")
		{
			THEN("Perimeter is correct")
			{
				double expectedPerimeter = 12.0;
				REQUIRE(triangle.GetPerimeter() == expectedPerimeter);
			}
		}
		WHEN("Calculating area")
		{
			THEN("Area is correct")
			{
				double expectedArea = 6.0;
				REQUIRE(triangle.GetArea() == expectedArea);
			}
		}
		WHEN("Converting to string")
		{
			THEN("String representation is correct")
			{
				std::string expectedString = "Triangle: (0.00, 0.00) (3.00, 0.00) (0.00, 4.00) area 6.00 perimeter 12.00 outline ff0000 fill ff00";
				REQUIRE(triangle.ToString() == expectedString);
			}
		}
	}
}

SCENARIO("Testing shape creator")
{
	GIVEN("Shape creator and some points")
	{
		ShapeCreator creator;
		CPoint p1(10, 10);
		CPoint p2(20, 20);
		CPoint p3(30, 15);

		CHECK(creator.GetShapes().empty());

		WHEN("Creating shapes")
		{
			creator.CreateLine(p1, p2, 0xFF0000);
			creator.CreateCircle(p1, 30, 0xFF0000, 0xFF0000);
			creator.CreateRectangle(p1, 30, 15, 0xFF0000);
			creator.CreateTriangle(p1, p2, p3, 0xFF0000, 0xFF0000);

			THEN("All shapes are created")
			{
				CHECK(creator.GetShapes().size() == 4);
			}

			AND_WHEN("Deleting shapes")
			{
				creator.ClearShapes();

				THEN("All shapes are deleted")
				{
					CHECK(creator.GetShapes().empty());
				}
			}
		}
	}
}
