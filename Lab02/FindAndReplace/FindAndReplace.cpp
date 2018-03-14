// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

std::string FindAndReplace(std::string& subject, std::string const& search, std::string const& replace);
void PrintWithReplace(std::string const& search, std::string const& replace);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Error: Invalid number of arguments";
	}
	std::string searchString = argv[1];
	std::string replaceString = argv[2];
	PrintWithReplace(searchString, replaceString);
    return 0;
}
void PrintWithReplace(std::string const& search, std::string const& replace)
{
	std::string subject;
	while (std::getline(std::cin, subject))
	{
		std::cout << FindAndReplace(subject, search, replace) << "\n";
		
	}
	
}

std::string FindAndReplace(std::string& subject, std::string const& search, std::string const& replace)
{
	while (subject.find(search) != -1)
	{
		size_t pos = subject.find(search);
		if (pos != std::string::npos)
		{
			subject.replace(pos, pos + search.length(), replace);
			std::cout << pos << ' ' << pos + search.length() <<' ' << subject << "\n";
		}
	}
	return subject;
}