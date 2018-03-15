// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

std::string FindAndReplace(std::string text, const std::string stringToSearch, std::string stringToReplace);
void PrintWithReplace(const std::string stringToSearch, std::string stringToReplace);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Error: Invalid number of arguments";
	}
	std::string stringToSearch = argv[1];
	std::string stringToReplace = argv[2];
	PrintWithReplace(stringToSearch, stringToReplace);
    return 0;
}
void PrintWithReplace(const std::string stringToSearch, std::string stringToReplace)
{
	std::string inputString;

	while (std::getline(std::cin, inputString))
	{
		std::cout << FindAndReplace(inputString, stringToSearch, stringToReplace) << "\n";
	}
	
}

std::string FindAndReplace(std::string text, const std::string stringToSearch, std::string stringToReplace)
{
	size_t position = 0;

	while ((position = text.find(stringToSearch, position)) != std::string::npos)
	{
		text.replace(position, stringToSearch.length(), stringToReplace);
		position += stringToReplace.length();
	}

	return text;
}