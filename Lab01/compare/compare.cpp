// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char * argv[])
{

	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream firstFile(argv[1]), secondFile(argv[2]);
	if (!firstFile.is_open() || !secondFile.is_open())
	{
		cout << "Failed to open file ";
		if (!firstFile.is_open())
		{
			cout << argv[1] << " ";
		}
		if (!secondFile.is_open())
		{
			cout << argv[2] << " ";
		}
		cout << "for reading\n";
		return 1;
	}

	string firstStr, secondStr;
	unsigned int lineCounter = 0;
	while (!firstFile.eof() && !secondFile.eof())
	{
		lineCounter++;
		getline(firstFile, firstStr);
		getline(secondFile, secondStr);
		if (firstStr != secondStr)
		{
			cout << "Files are different. Line number is " << lineCounter << "\n";
			return 1;
		}
		if ((!firstFile.eof() && secondFile.eof()) || (firstFile.eof() && !secondFile.eof()))
		{
			cout << "Files are different. Line number is " << lineCounter << "\n";
			return 1;
		}
	}

	cout << "Files are equal\n";
	return 0;
}

