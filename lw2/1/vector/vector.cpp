/*
Каждый элемент массива должен быть умножен на минимальный элемент исходного массива Подсказка: используйте алгоритм std::min_element.
*/

#include "ProcessVector.h"

int main()
{
	std::vector<double> numbers = ReadData();
	ProcessVector(numbers);
	PrintVector(numbers);
	return 0;
}

