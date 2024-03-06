
#include <iostream>
#include <iterator>
#include <vector>


int main()
{
	std::vector<double> numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
}