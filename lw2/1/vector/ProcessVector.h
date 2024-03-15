#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>


std::vector<double> GetVector(std::istream& inputStream);
void MultiplyOnMinimumVectorElement(std::vector<double>& numbers);
void PrintVector(std::vector<double>& numbers);