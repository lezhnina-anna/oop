// Lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FindMaxEx.h"

int main()
{
	std::vector<int> intV= {1, 5, 0, 4};
	int max;

	FindMax(intV, max, [](auto& l, auto& r) {
		return l < r;
	});

	std::cout << max << std::endl;

    return 0;
}
