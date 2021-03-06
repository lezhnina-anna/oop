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
	
	string input;
	int count = 1;
	std::cout << "Enter v0 (or type 'exit') ";
	getline(cin, input);
	enum inputParameter { angle, speed };
	double alpha, startSpeed;
	inputParameter currentParameter = speed;
	do
	{
		if (input == "exit")
		{
			std::cout << "Goodbye\n";
			return 0;
		}
		switch (currentParameter)
		{
		case speed:
			startSpeed = strtod(input.c_str(), NULL);
			currentParameter = angle;
			std::cout << "Enter a0 (or type 'exit') ";
			break;
		case angle:
			alpha = strtod(input.c_str(), NULL);
			currentParameter = speed;
			if ((startSpeed <= 0) || ((alpha <= 0) || (alpha >= 90)))
			{
				std::cout << "invalid argument\n";
			}
			else
			{
				std::cout << "The Distanse is " << (CalculateDistance(alpha, startSpeed)) << "\n";
			}
			std::cout << "Enter v0 (or type 'exit') ";
			break;
		} 
	} while (getline(cin, input));
	return 0;
}

