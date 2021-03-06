// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

int SumDigits(int i)

{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char* argv[])

{
	int i, upperBound;
	upperBound = atoi(argv[1]);
	for (i = 1; i <= upperBound; ++i)
	{
		if (i % SumDigits(i) == 0)
		{
			if (i != 1)
			{
				printf(", ");
			}
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}
