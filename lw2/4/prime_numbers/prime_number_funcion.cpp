#include "/OOP/lw2/4/prime_numbers/prime_number.h"

constexpr int maxUpperBound = 100000000;


std::set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	std::set<int> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}
	primeNumbers.insert(2);
	std::vector<bool> isPrime(upperBound + 1, true);
	for (int i = 3; i <= upperBound; i += 2)
	{
		if (isPrime[i])
		{
			primeNumbers.insert(i);
			for (int j = i + i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	return primeNumbers;
}

void PrintPrimeNumber(std::set<int> primeNumbersSet)
{
	if (primeNumbersSet.empty())
	{
		std::cout << "No prime numbers!" << std::endl;
	}
	for (auto primeNumber : primeNumbersSet)
	{
		std::cout << primeNumber << " ";
	}
	std::cout << '\n';
}

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
