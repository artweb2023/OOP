#include "CarApp.h"
#include "ClassCar.h"

int main()
{
	Car car;
	CarApp carApp(car, std::cin, std::cout);
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!carApp.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}
