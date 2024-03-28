#pragma once

#include <iostream>
#include <set>
#include <vector>

// использовать заголовки только те которые используются в данном обявелнии 

std::set<int> GeneratePrimeNumbersSet(const int upperBound);
void PrintPrimeNumber(std::set<int> primeNumbersSet);