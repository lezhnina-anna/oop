// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>

const int MATRIX_SIZE = 3;
using Matrix3x3 = std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE>;
bool ReadMatrix(std::ifstream & inputFile, Matrix3x3 & matrix)
{
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

bool ReadMatrix(const std::string & inputFileName, Matrix3x3 & matrix)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open() || !ReadMatrix(inputFile, matrix))
	{
	    return false;
	}
	return true;
}

void PrintMatrix(const Matrix3x3 & matrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << std::setprecision(4) << matrix[i][j] << " ";
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
	if (ReadMatrix(firstInputFile, firstMatrix) && ReadMatrix(secondInputFile, secondMatrix))
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

