#include "ProcessVector.h"

std::vector<double> GetVector(std::istream& inputStream)
{
	std::vector<double> vector;
	double value;
	while (inputStream >> value)
	{
		vector.push_back(value);
	}
	if (!inputStream.eof())
	{
		throw std::runtime_error("Invalid values!");
	}
	return vector;
}

void MultiplyOnMinimumVectorElement(std::vector<double>& numbers) {
	if (numbers.empty()) {
		return;
	}
	double minElement = *std::min_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [minElement](double element) {
		return element * minElement;
		});
}

void SortVector(std::vector<double>& numbers)
{
	if (numbers.empty())
	{
		return;
	}
	std::sort(numbers.begin(), numbers.end());
}

void PrintVector(std::vector<double>& numbers)
{
	for (auto num : numbers)
	{
		std::cout << std::fixed << std::setprecision(2) << num << " ";
	}
	std::cout << '\n';
}
