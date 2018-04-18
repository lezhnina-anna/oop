#include "stdafx.h"
#include "..\GeneratePrimeNumbers\GeneratePrimes.h"
#include <ctime>

bool SetsAreEqual(std::set<int> & x, std::set<int> & y)
{
	return x == y;
}

bool SetsSizesAreEqual(size_t x, size_t y)
{

	return x == y;
}

bool ExecutionTimeIsWithinTheAllowableRange(int maxTime, int executionTime)
{
	return maxTime > executionTime;
}

BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)

	BOOST_AUTO_TEST_CASE(generate_primes_where_upper_bound_is_within_the_allowable_range)
	{
		const int upperBound = 10;
		std::set<int> expectedSet = { 2, 3, 5, 7 };
		std::set<int> outputSet = GeneratePrimeNumbersSet(upperBound);
		BOOST_CHECK(SetsAreEqual(expectedSet, outputSet));
	}

	BOOST_AUTO_TEST_CASE(generate_primes_where_upper_bound_is_out_of_the_allowable_range)
	{
		const int upperBound = 0;
		std::set<int> expectedSet = {};
		std::set<int> outputSet = GeneratePrimeNumbersSet(upperBound);
		BOOST_CHECK(SetsAreEqual(expectedSet, outputSet));
	}

	#ifndef _DEBUG  
	BOOST_AUTO_TEST_CASE(check_execution_time_and_output_set_size_with_max_upper_bound)
	{
		const int upperBound = 100000000;

		unsigned int startTime = clock();
		std::set<int> numbersSet = GeneratePrimeNumbersSet(upperBound);
		unsigned int endTime = clock(); 
		unsigned int executionTime = endTime - startTime;

		const int MAX_EXECUTION_TIME = 12000;
		BOOST_CHECK(ExecutionTimeIsWithinTheAllowableRange(MAX_EXECUTION_TIME, executionTime));

		const int EXPECTED_SIZE = 5761455;
		BOOST_CHECK(SetsSizesAreEqual(EXPECTED_SIZE, numbersSet.size()));
}
	#endif

BOOST_AUTO_TEST_SUITE_END()