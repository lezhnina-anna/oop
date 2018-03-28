#include "stdafx.h"
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "processVector.h"

void ProcessVector(std::vector<double>& numbers)
{
	const double minNumber = *std::min_element(begin(numbers), end(numbers));
	const double maxNumber = *std::max_element(begin(numbers), end(numbers));

	auto processNumber = [&minNumber, &maxNumber](double number) {
		if (maxNumber == 0)
		{
			return abs(number * minNumber);
		}
		return (number * minNumber / maxNumber);
	};

	std::transform(numbers.begin(), numbers.end(), numbers.begin(), processNumber);
}