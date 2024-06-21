#include "FindMaxEx.h"
#include <iostream>
#include <string>
#include <vector>

struct Athlete
{
	std::string name;
	double height;
	double weight;
};

int main()
{
	std::vector<Athlete> athletes = {
		   {"Ivan Petrov", 180.5, 75.5},
		   {"Peter Ivanov", 175.9, 65.5},
		   {"Mike Sidorov", 190.2, 55.5},
		   {"Anna Ziga", 170.4, 55.4}
	};
	auto compareByHeight = [](const Athlete& a, const Athlete& b) {
		return a.height < b.height;
		};

	auto compareByWeight = [](const Athlete& a, const Athlete& b) {
		return a.weight < b.weight;
		};
	Athlete tallest;
	Athlete heaviest;
	if (FindMaxEx(athletes, tallest, compareByHeight))
	{
		std::cout << "Tallest athlete: " << tallest.name << "\n";
	}

	if (FindMaxEx(athletes, heaviest, compareByWeight))
	{
		std::cout << "Heaviest athlete: " << heaviest.name << "\n";
	}
}