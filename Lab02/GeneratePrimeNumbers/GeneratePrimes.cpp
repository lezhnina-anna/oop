#include "stdafx.h"

std::vector<bool> GeneratePrimeNumbers(const int upperBound)
{
	std::vector<bool> primes(upperBound + 1, true);

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
			primesSet.insert(i);
		}
	}

	return primesSet;
}

