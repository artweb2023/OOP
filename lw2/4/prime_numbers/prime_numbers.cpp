#include "ParseArgs.h"
#include "prime_number.h"

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	PrintPrimeNumber(GeneratePrimeNumbersSet(*args));
	return 0;
}
