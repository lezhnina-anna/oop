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

		auto processNumber = [&minNumber, &maxNumber](double number) {
			if (maxNumber == 0)
			{
				return (number * minNumber);
			}
			return (number * minNumber / maxNumber);
		};

		std::transform(numbers.begin(), numbers.end(), numbers.begin(), processNumber);
	}
}
