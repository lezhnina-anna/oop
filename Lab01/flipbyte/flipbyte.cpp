// reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <string> 
using namespace std;

unsigned int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

uint8_t FlipBits(uint8_t x)
{
	int base = 256;
	uint8_t res = 0;
	while (x != 0)
	{
		res += (x & 1) * (base >>= 1);
		x >>= 1;
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
	if ((not err) && (decNum >= 0) && (decNum <= 255))
	{
		auto bits = static_cast<uint8_t>(decNum);
		unsigned int reverseBits = FlipBits(bits);
		std::cout << reverseBits << std::endl;
	}
	else
	{
		printf("Invalid number\n");
		return 1;
	}
	return 0;
}