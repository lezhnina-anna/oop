// Task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

double CalculateDistance(double alpha, double speed)
{
	const double PI = 3.1415926535, g = 9.8;
	double radianAlpha = (alpha * PI) / 180;
	double distance = (speed * speed * sin(2 * radianAlpha)) / g;
	return distance;
}

int main(int argc, char * argv[])
{
	double alpha, speed;
	string input;
	int count = 1;
	std::cout << "Enter v0 (or type 'exit') ";
	getline(cin, input);
	do
	{
		if (input == "exit")
		{
			std::cout << "Goodbye\n";
			return 0;
		}
		else
		{
			if (count == 1)
			{
				speed = strtod(input.c_str(), NULL);
				count = 2;
			}
			else
			{
				alpha = strtod(input.c_str(), NULL);
				if ((speed <= 0) || ((alpha <= 0) || (alpha >= 90)))
				{
					std::cout << "invalid argument\n";
				}
				else
				{
					std::cout << "The Distanse is " << (CalculateDistance(alpha, speed)) << "\n";
				}
				count = 1;
			}

			std::cout << "Enter ";
			if (count == 1) //скорость
				std::cout << "v0 ";
			else //угол
				std::cout << "a0 ";
			std::cout << "(or type 'exit') ";
		}

	} while (getline(cin, input));
	std::system("pause");
	return 0;
}

