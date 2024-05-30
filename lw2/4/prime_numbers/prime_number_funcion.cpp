#include "/OOP/lw2/4/prime_numbers/prime_number.h"

constexpr int firstPrimeNum = 2;

// подумать как убысрить цикл
std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	//повторить в каком порядке 
	//время вставки и поиска удаления элементов
	std::set<int> primeNumbers;
	if (upperBound < firstPrimeNum)
	{
		return primeNumbers;
	}
	primeNumbers.insert(firstPrimeNum);
	std::vector<bool> isPrime(upperBound + 1, true);
	//разделить циклы 
	for (int i = 3; i <= upperBound; i += 2)
	{
		if (isPrime[i])
		{
			//использовать метом insert с подсказкой
			primeNumbers.insert(primeNumbers.end(), i);
			// вырезать числа с квадратом , и с шагом 2
			if (i <= std::sqrt(upperBound))
			{
				for (int j = i * 2; j <= upperBound; j += i)
				{
					isPrime[j] = false;
				}
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


