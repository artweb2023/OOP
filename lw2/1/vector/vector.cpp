#include "ProcessVector.h"

int main()
{
	try
	{
		auto numbers = GetVector(std::cin);
		MultiplyOnMinimumVectorElement(numbers);
		std::ranges::sort(numbers);
		PrintVector(numbers);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}
