#pragma once
#include "stdafx.h"

template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> & arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	auto max = arr.begin();

	for (auto element = arr.begin() + 1; element != arr.end(); ++element)
	{
		if (less(*max, *element))
		{
			max = element;
		}
	}

	maxValue = *max;

	return true;
}