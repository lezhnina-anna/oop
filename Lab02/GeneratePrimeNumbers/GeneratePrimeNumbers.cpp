// GeneratePrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

const int MAX_VALUE = 100000000;

std::vector<bool> GeneratePrimeNumbers(const int upperBound)
{
	std::vector<bool> primes(upperBound + 1, true);

	primes[0] = primes[1] = false;

	for (int i = 2; i <= sqrt(upperBound); ++i)
	{
		if ((primes[i]) && (i * i <= upperBound))
		{
			for (int j = i * i; j <= upperBound; j += i)
			{
				primes[j] = false;
			}
		}
	}

	return primes;
}

void PrintPrimeNumbersSet(std::vector<bool> & primesSet)
{
	copy(primesSet.begin(), primesSet.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> primesVector = GeneratePrimeNumbers(upperBound);
	PrintPrimeNumbersSet(primesVector);
	std::set<int> primesSet;
	/*
	for (int i = 0; i <= upperBound; ++i)
	{
		if (primesVector[i])
		{
			primesSet.insert(i);
		}
	}*/

	return primesSet;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid arguments count" << std::endl;
		return 1;
	}

	int upperBound = atoi(argv[1]);

	if (upperBound > MAX_VALUE)
	{
		std::cout << "Error: Too big value. Max value is " << MAX_VALUE << std::endl;
		return 1;
	}

	std::set<int> primesSet = GeneratePrimeNumbersSet(upperBound);
	//PrintPrimeNumbersSet(primesSet);

    return 0;
}

