// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

int ReadMatrix(double(&matrix)[3][3], std::istream & inputFile, bool & err)
{
	for (std::size_t i = 0; i <= 2; i++)
	{
		for (std::size_t j = 0; j <= 2; j++)
		{
			if (!inputFile.eof())
			{
				inputFile >> matrix[i][j];
			}
			else
			{
				err = true;
				return 1;
			}
		}
	}
	err = false;
	return 0;
}

int Multiply(double(&firstMatrix)[3][3], double(&secondMatrix)[3][3], double(&result)[3][3])
{
	for (std::size_t i = 0; i <= 2; i++)
	{
		for (std::size_t j = 0; j <= 2; j++)
		{
			for (std::size_t element = 0; element <= 2; element++)
			{
				result[i][j] += firstMatrix[i][element] * secondMatrix[element][j];
			}
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 1;
}

int main(int argc, char * argv[])
{
	typedef double Matrix3x3[3][3];
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: multmatrix.exe <first input file> <second input file>\n";
		return 1;
	}
	std::ifstream firstInputFile(argv[1]), secondInputFile(argv[2]);
	if (!(firstInputFile.is_open() && secondInputFile.is_open()))
	{
		std::cout << "Error: failed to open files for reading" << std::endl;
		return 1;
	}
	Matrix3x3 firstMatrix, secondMatrix;
	bool err;
	ReadMatrix(firstMatrix, firstInputFile, err);
	ReadMatrix(secondMatrix, secondInputFile, err);
	if (err)
	{
		std::cout << "Error: Invalid input" << std::endl;
		return 1;
	}
	Matrix3x3 resultMatrix = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	Multiply(firstMatrix, secondMatrix, resultMatrix);
	return 0;
}

