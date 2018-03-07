// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <array>

const int MATRIX_SIZE = 3;
using Matrix3x3 = std::array<std::array<int, MATRIX_SIZE>, MATRIX_SIZE>;

bool ReadMatrix(Matrix3x3 & matrix, const std::string inputFileName)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		return false;
	}
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
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

void PrintMatrix(const Matrix3x3 & matrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Multiply(const Matrix3x3 & firstMatrix, const Matrix3x3 & secondMatrix, Matrix3x3 & result)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			for (size_t element = 0; element < MATRIX_SIZE; element++)
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
	Matrix3x3 firstMatrix = { 0 }, secondMatrix = { 0 };
	if (ReadMatrix(firstMatrix, firstInputFile) && ReadMatrix(secondMatrix, secondInputFile))
	{
		Matrix3x3 resultMatrix = { 0 };
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

