#include "Solve.h"

int main()
{
	while (!std::cin.eof() && !std::cin.fail())
	{
		try
		{
			double a, b, c;
			std::cin >> a;
			std::cin >> b;
			std::cin >> c;
			PrintResult(Solve(a, b, c));
		}
		catch (std::invalid_argument const& e)
		{
			std::cout << "Error argument: " << e.what() << "\n";
		}
		catch (std::domain_error const& e)
		{
			std::cout << "Error solutions: " << e.what() << "\n";
		}
		catch (const std::exception& e)
		{
			std::cout << "Error :" << e.what() << std::endl;
		}
	}
	return 0;
}