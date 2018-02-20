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

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Invalid number of arguments.\n");
		return 0;
	}

	bool err;
	int param = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not a number\n.");
		return 1;
	}

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
		if ((number > 0) && (prevNumber > INT_MAX - number))
		{
			printf("Overflow\n");
			return 1;
		}
		printf("%d", number);
		temp = number;
		number += prevNumber;
		prevNumber = temp;
		++count;
	}
	printf("\n");
	return 0;
}
