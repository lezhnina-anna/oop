// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "processVector.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>

std::vector<double> ReadVectorFromInputStream()
{
	std::vector<double> numbers;
	std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), back_inserter(numbers));
	return numbers;
}

void PrintVector(const std::vector<double>& numbers)
{
	std::cout << std::setprecision(3);
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
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
