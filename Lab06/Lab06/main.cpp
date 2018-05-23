// Lab06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HttpUrl.h"
#include <iostream>

int main()
{
	/*CHttpUrl check("https://vk.com/news");
	std::cout << check.GetProtocol() << std::endl;
	std::cout << check.GetDocument() << std::endl;
	std::cout << check.GetDomain() << std::endl;
	std::cout << check.GetPort() << std::endl;
	
	CHttpUrl check1("vk.com", "/qwer/ty");
	std::cout << check1.GetProtocol() << std::endl;
	std::cout << check1.GetDocument() << std::endl;
	std::cout << check1.GetDomain() << std::endl;
	std::cout << check1.GetPort() << std::endl;
	std::cout <<  std::endl;*/
	CHttpUrl check2("vk.com", "/qwer/ty", Protocol::HTTPS, 43);
	std::cout << check2.GetProtocol() << std::endl;
	std::cout << check2.GetDocument() << std::endl;
	std::cout << check2.GetDomain() << std::endl;
	std::cout << check2.GetPort() << std::endl;
	std::cout << check2.GetURL() << std::endl;

    return 0;
}

