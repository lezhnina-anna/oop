// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FindAndReplace.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void PrintWithReplace(const std::string & stringToSearch, const std::string & stringToReplace);

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::string stringToSearch = argv[1];
	std::string stringToReplace = argv[2];

	PrintWithReplace(stringToSearch, stringToReplace);

	return 0;
}
void PrintWithReplace(const std::string & stringToSearch, const std::string & stringToReplace)
{
	std::string inputString;

	while (std::getline(std::cin, inputString))
	{
		std::cout << FindAndReplace(inputString, stringToSearch, stringToReplace) << "\n";
	}
}
