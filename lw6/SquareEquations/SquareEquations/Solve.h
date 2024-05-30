#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>


struct EquationRoots
{
	int numRoots;
	double roots[2];
};

EquationRoots Solve(double a, double b, double c);
void PrintResult(const EquationRoots& roots);