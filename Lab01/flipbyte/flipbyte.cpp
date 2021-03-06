// reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

unsigned int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

uint8_t FlipBits(uint8_t number)
{
	int base = 256;
	uint8_t res = 0;
	while (number != 0)
	{
		res += (number & 1) * (base >>= 1);
		number >>= 1;
	}
	return res;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <number>\n";
		return 1;
	}
	bool err = false;
	unsigned int decNum = StringToInt(argv[1], err);
	if ((!err) && (decNum >= 0) && (decNum <= 255))
	{
		auto bits = static_cast<uint8_t>(decNum);
		unsigned int reversedBits = FlipBits(bits);
		std::cout << reversedBits << std::endl;
	}
	else
	{
		std::cout << "Invalid number" << std::endl;
		return 1;
	}
	return 0;
}