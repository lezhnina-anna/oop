#include "stdafx.h"
#include "processVector.h"
#include <algorithm>

void ProcessVector(std::vector<double>& numbers)
{
	if (!numbers.empty())
	{
		auto result = std::minmax_element(numbers.begin(), numbers.end());
		double minNumber = *result.first;
		double maxNumber = *result.second;

		double argument = minNumber;
		if (maxNumber != 0)
		{
			argument /= maxNumber;
		}

		auto processNumber = [&argument](double number) {
			return (number * argument);
		};

		std::transform(numbers.begin(), numbers.end(), numbers.begin(), processNumber);
	}
}
