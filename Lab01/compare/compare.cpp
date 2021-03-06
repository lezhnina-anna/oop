// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int ERROR = -1;
const int EQUAL_FILES = 0;

int Compare(std::string & firstFileName, std::string & secondFileName);
int Compare(std::ifstream & firstFile, std::ifstream & secondFile)
{
	string firstStr, secondStr;
	unsigned int lineCounter = 0;

	while (firstFile && secondFile)
	{
		++lineCounter;
		getline(firstFile, firstStr);
		getline(secondFile, secondStr);
		if (firstStr != secondStr)
		{
			return lineCounter;
		}
	}

	if (!secondFile.eof() || !firstFile.eof())
	{
		return ++lineCounter;
	}

	return EQUAL_FILES;
}

int main(int argc, char * argv[])
{

	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	std::string firstFileName = argv[1];
	std::string secondFileName = argv[2];
	int lineNumber = Compare(firstFileName, secondFileName);

	switch (lineNumber)
	{
	case ERROR:
		cout << "Failed to open files for reading\n";
		return 1;
		break;
	case EQUAL_FILES:
		cout << "Files are equal\n";
		break;
	default:
		cout << "Files are different. Line number is " << lineNumber << "\n";
		break;
	}

	return 0;
}

int Compare(std::string & firstFileName, std::string & secondFileName)
{
	ifstream firstFile(firstFileName);
	ifstream secondFile(secondFileName);

	if (!firstFile.is_open() || !secondFile.is_open())
	{
		return ERROR;
	}

	return Compare(firstFile, secondFile);
}

