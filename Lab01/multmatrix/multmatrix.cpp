// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

typedef double Matrix3x3[3][3];

bool ReadMatrix(Matrix3x3 matrix, std::string inputFileName)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		return false;
	}
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
				return false;
			}
		}
	}
	return true;
}

void PrintMatrix(Matrix3x3 & matrix)
{
	for (std::size_t i = 0; i <= 2; i++)
	{
		for (std::size_t j = 0; j <= 2; j++)
		{
			std::cout << matrix[i][j] << " ";
			if (j == 2)
			{
				std::cout << std::endl;
			}
		}
	}
}

void Multiply(Matrix3x3 & firstMatrix, Matrix3x3 & secondMatrix, Matrix3x3 & result)
{
	for (std::size_t i = 0; i <= 2; i++)
	{
		for (std::size_t j = 0; j <= 2; j++)
		{
			for (std::size_t element = 0; element <= 2; element++)
			{
				result[i][j] += firstMatrix[i][element] * secondMatrix[element][j];
			}
		}
	}
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: multmatrix.exe <first input file> <second input file>\n";
		return 1;
	}
	std::string firstInputFile = argv[1];
	std::string secondInputFile = argv[2];
	Matrix3x3 firstMatrix, secondMatrix;
	if (ReadMatrix(firstMatrix, firstInputFile) && ReadMatrix(secondMatrix, secondInputFile))
	{
		Matrix3x3 resultMatrix = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
		Multiply(firstMatrix, secondMatrix, resultMatrix);
		PrintMatrix(resultMatrix);
	}
	else
	{
		std::cout << "Error: Invalid input" << std::endl;
		return 1;
	}
	return 0;
}

