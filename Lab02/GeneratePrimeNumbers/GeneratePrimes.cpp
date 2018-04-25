#include "stdafx.h"

const int MAX_VALUE = 100000000;
const int MIN_VALUE = 2;

std::vector<bool> GeneratePrimeNumbers(const int upperBound)
{
	std::vector<bool> isPrimes(upperBound + 1, true);

	if (upperBound > MAX_VALUE || upperBound < MIN_VALUE)
	{
		return {};
	}

	isPrimes[0] = isPrimes[1] = false;

	for (unsigned int i = 2; i * i < isPrimes.size(); ++i)
	{
		if (isPrimes[i])
		{
			for (unsigned int j = i * i; j < isPrimes.size(); j += i)
			{
				isPrimes[j] = false;
			}
		}
	}

	return isPrimes;
}

std::set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	auto primeNumbers = GeneratePrimeNumbers(upperBound);
	std::set<int> primesSet;

	for (unsigned int i = 0; i < primeNumbers.size(); ++i)
	{
		if (primeNumbers[i])
		{
			primesSet.insert(primesSet.end(), i);
		}
	}

	return primesSet;
}
