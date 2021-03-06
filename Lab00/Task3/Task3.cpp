// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

int StringToInt(const char * str, bool & err)

{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int PrintFibonacciNumbers(int upperBound, bool & err)
{
	int number = 1, prevNumber = 0, count = 0;
	while (number <= upperBound)
	{
		if (count == 5)
		{
			printf("\n");
			count = 0;
		}
		else if (count != 0)
		{
			printf(", ");
		}
		
		err = ((number > 0) && (prevNumber > INT_MAX - number));
		if (not err)
		{
			printf("%d", number);
			number += prevNumber;
			prevNumber = number - prevNumber;
			++count;
		}
		else
		{
			printf("%d\n", number);
			return 1;
		}

	}
	printf("\n");
	return 0;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Invalid number of arguments\n");
		return 1;
	}

	bool err;
	int upperBound = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not a number\n");
		return 1;
	}

	if (upperBound <= 0)
	{
		printf("Invalid argument\n");
		return 1;
	}

	PrintFibonacciNumbers(upperBound, err);
	if ((err) && ((upperBound + 1) < 0))
	{
	    printf("Overflow\n");
	    return 1;
	}
	return 0;
}
