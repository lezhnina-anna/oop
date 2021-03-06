// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>

const int MATRIX_SIZE = 3;
using Matrix3x3 = std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE>;
bool FillMatrix(std::ifstream  & inputFile, Matrix3x3 & matrix)
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
				throw std::logic_error("Error: Invalid input");
			}
		}
	}
	return true;
}

Matrix3x3 ReadMatrix(const std::string inputFileName)
{
	std::ifstream inputFile(inputFileName);
	Matrix3x3 matrix = { 0 };
	if (!inputFile.is_open() || !FillMatrix(inputFile, matrix))
	{
		throw std::runtime_error("Error: Filed to open input file");
	}
	return matrix;
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

Matrix3x3 Multiply(const Matrix3x3 & firstMatrix, const Matrix3x3 & secondMatrix)
{
	Matrix3x3 resultMatrix = { 0 };
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			for (size_t element = 0; element < MATRIX_SIZE; element++)
			{
				resultMatrix[i][j] += firstMatrix[i][element] * secondMatrix[element][j];
			}
		}
	}
	return resultMatrix;
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

	Matrix3x3 firstMatrix = { 0 };
	Matrix3x3 secondMatrix = { 0 };

	try
	{
		firstMatrix = ReadMatrix(firstInputFile);
		secondMatrix = ReadMatrix(secondInputFile);
		Matrix3x3 resultMatrix = Multiply(firstMatrix, secondMatrix);
		PrintMatrix(resultMatrix);
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}

