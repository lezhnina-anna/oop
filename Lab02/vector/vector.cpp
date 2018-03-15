// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

std::vector<double> ReadVectorFromInputStream()
{
	std::vector<double> numbers;
    std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), back_inserter(numbers));
	return numbers;
}
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
void PrintVector(const std::vector<double>& numbers)
{
    copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
}

int main()
{
	std::vector<double> numbers = ReadVectorFromInputStream();
    ProcessVector(numbers);

    std::sort(numbers.begin(), numbers.end());
    PrintVector(numbers);

    return 0;
}

