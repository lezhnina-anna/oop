// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int compare(std::istream & firstFile, std::istream & secondFile);

int main(int argc, char * argv[])
{

	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

    ifstream firstFile(argv[1]);
    ifstream secondFile(argv[2]);
	if (!firstFile.is_open())
	{
		cout << "Failed to open file ";
		cout << argv[1] << " ";
		cout << "for reading\n";
		return 1;
	}
	if (!secondFile.is_open())
	{
		cout << "Failed to open file ";
		cout << argv[2] << " ";
		cout << "for reading\n";
		return 1;
	}
	int lineNumber = compare(firstFile, secondFile);
	if (lineNumber == 0)
	{
		cout << "Files are equal\n";
	}
	else
	{
		cout << "Files are different. Line number is " << lineNumber << "\n";
	}
	return 0;
}


int compare(std::istream & firstFile, std::istream & secondFile)
{
	string firstStr, secondStr;
	unsigned int lineCounter = 0;
	while (!firstFile.eof() && !secondFile.eof())
	{
		++lineCounter;
		getline(firstFile, firstStr);
		getline(secondFile, secondStr);
		if (firstStr != secondStr)
		{
			return lineCounter;
		}
	}
	if ((!firstFile.eof() && secondFile.eof()) || (firstFile.eof() && !secondFile.eof()))
	{
		return ++lineCounter;
	}
	return 0;
}

