#include "ProcessVector.h"

std::vector<double> ReadData()
{
	std::vector<double> numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	return numbers;
}

void ProcessVector(std::vector<double>& numbers)
{
	if (!numbers.empty()) {
		auto minElement = std::min_element(numbers.begin(), numbers.end());
		for (double& num : numbers)
		{
			num *= *minElement;
		}
	}
}

void PrintVector(std::vector<double>& numbers)
{
	std::sort(numbers.begin(), numbers.end());
	for (auto num : numbers)
	{
		std::cout << std::fixed << std::setprecision(2) << num << " ";
	}
	std::cout << '\n';
}
