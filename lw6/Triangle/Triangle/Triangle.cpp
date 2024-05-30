#include "CTriangle.h"
#include <iostream>

int main() 
{
	while (!std::cin.eof() && !std::cin.fail())
	{
		try
		{
			double side1, side2, side3;
			std::cin >> side1;
			std::cin >> side2;
			std::cin >> side3;
			CTriangle triangle(side1, side2, side3);
			std::cout << "Triangle perimeter: " << triangle.GetPerimeter() << std::endl;
			std::cout << "Triangle area: " << triangle.GetArea() << std::endl;
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Error parsing argument : " << e.what() << std::endl;
		}
		catch (const std::domain_error& e)
		{
			std::cout << "Error Side: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}