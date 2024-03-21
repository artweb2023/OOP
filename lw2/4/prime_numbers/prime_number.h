#pragma once

#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <vector>

std::set<int> GeneratePrimeNumbersSet(const int upperBound);
std::optional<int> ParseArgs(int argc, char* argv[]);
void PrintPrimeNumber(std::set<int> primeNumbersSet);