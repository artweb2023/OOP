/*
Каждый элемент массива должен быть умножен на минимальный элемент исходного массива Подсказка: используйте алгоритм std::min_element.
*/

#include "ProcessVector.h"

int main()
{
	try
	{
		auto numbers = GetVector(std::cin);
		MultiplyOnMinimumVectorElement(numbers);
		SortVector(numbers);
		PrintVector(numbers);
		return 0;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return 1;
	}
}
