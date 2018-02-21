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

int PrintNumbers(int param, bool & err)
{
	int number = 1, prevNumber = 0, temp, count = 0;
	while (number <= param)
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
			temp = number;
			number += prevNumber;
			prevNumber = temp;
			++count;
		}
		else
		{
			printf("%d\n", number);
			return 1;
		}

	}
	return 0;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Invalid number of arguments");
		return 1;
	}

	bool err;
	int param = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not a number");
		return 1;
	}

	if (param <= 0)
	{
		printf("Invalid argument");
		return 1;
	}

	PrintNumbers(param, err);
	if (err)
	{
	    printf("Overflow");
	    return 1;
	}
	printf("\n");
	return 0;
}
