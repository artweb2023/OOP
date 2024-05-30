#include "Solve.h"


EquationRoots Solve(double a, double b, double c)
{
	if (a == 0)
	{
		throw std::invalid_argument("the argument must be != 0");
	}
	double discriminant = b * b - 4 * a * c;
	EquationRoots roots;
	if (discriminant < 0)
	{
		throw std::domain_error("A quadratic equation may not have real roots");
	}
	else if (discriminant == 0)
	{
		roots.numRoots = 1;
		roots.roots[0] = -b / (2 * a);
	}
	else
	{
		roots.numRoots = 2;
		roots.roots[0] = (-b + sqrt(discriminant)) / (2 * a);
		roots.roots[1] = (-b - sqrt(discriminant)) / (2 * a);
	}
	return roots;
}

void PrintResult(const EquationRoots& roots)
{
	if (roots.numRoots == 1)
	{
		std::cout << "Root: " << roots.roots[0] << std::endl;
	}
	else
	{
		std::cout << "Roots: " << roots.roots[0] << "," << roots.roots[1] << std::endl;
	}
}