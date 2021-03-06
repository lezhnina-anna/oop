// GeneratePrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratePrimes.h"

void PrintPrimeNumbersSet(std::set<int>& primesSet)
{
	copy(primesSet.begin(), primesSet.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid arguments count" << std::endl;
		return 1;
	}

	int upperBound = atoi(argv[1]);

	std::set<int> primesSet = GeneratePrimeNumbersSet(upperBound);
	if (!primesSet.empty())
	{
		PrintPrimeNumbersSet(primesSet);
	}
	else
	{
		std::cout << upperBound << " is out of range!";
	}

	return 0;
}
