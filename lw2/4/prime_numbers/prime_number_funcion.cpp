#include "/OOP/lw2/4/prime_numbers/prime_number.h"

constexpr int firstPrimeNum = 2;

// подумать как убысрить цикл
std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primeNumbers;
	if (upperBound < firstPrimeNum)
	{
		return primeNumbers;
	}
	primeNumbers.insert(firstPrimeNum);
	std::vector<bool> isPrime(upperBound + 1, true);
	for (int i = 2; i <= upperBound; ++i) {
		if (isPrime[i]) {
			primeNumbers.insert(i);
			for (int j = i * 2; j <= upperBound; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return primeNumbers;
}

void PrintPrimeNumber(const std::set<int>& primeNumbersSet)
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


