#pragma once
#include <stdexcept>
#include <vector>

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}
	auto itMax = arr.begin();
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (less(*itMax, *it))
		{
			itMax = it;
		}
	}
	maxValue = *itMax;
	return true;
}
