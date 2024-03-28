#include "ParseArgs.h"

constexpr int maxUpperBound = 100000000;

// выделить в отдельный модуль
std::optional<int> ParseArgs(int argc, char* argv[])
{
	int upperBound;
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: prime_numbers.exe <number>" << std::endl;
		return std::nullopt;
	}
	try
	{
		int number = std::stoi(argv[1]);
		if (number < 0 || number > maxUpperBound)
		{
			std::cout << "The number out of range" << std::endl;
			return std::nullopt;
		}
		upperBound = number;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return std::nullopt;
	}
	return upperBound;
}