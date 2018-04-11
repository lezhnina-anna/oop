#include "stdafx.h"

const int MAX_VALUE = 100000000;
const int MIN_VALUE = 2;

std::vector<bool> GeneratePrimeNumbers(const int upperBound)
{
	std::vector<bool> primes(upperBound + 1, true);

	if (upperBound > MAX_VALUE || upperBound < MIN_VALUE)
	{
		return primes = {};
	}

	primes[0] = primes[1] = false;

	for (size_t i = 2; i * i < primes.size(); ++i)
	{
		if (primes[i])
		{
			for (size_t j = i * i; j < primes.size(); j += i)
			{
				primes[j] = false;
			}
		}
	}

	return primes;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> primesVector = GeneratePrimeNumbers(upperBound);
	std::set<int> primesSet;

	for (size_t i = 0; i < primesVector.size(); ++i)
	{
		if (primesVector[i])
		{
			primesSet.insert(primesSet.end(), i);
		}
	}

	return primesSet;
}
