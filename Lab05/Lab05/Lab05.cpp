// Lab05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CRational.h"
#include <iostream>

int main()
{
	CRational rat;
	std::cout << rat << std::endl;

	CRational rat1(1, 0);
	std::cout << rat1 << std::endl;

	CRational rat2(0, 1);
	std::cout << rat2 << std::endl;

	CRational rat3(4, 1);
	std::cout << rat3 << std::endl;

	CRational rat4(2, 2);
	std::cout << rat4 << std::endl;

	CRational rat5(1, 2);
	std::cout << rat5 << std::endl;
}

