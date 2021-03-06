// Lab06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"
#include <iostream>

int main()
{
	std::string urlStr;
	std::cout << "Enter url: " << "\n";

	while (getline(std::cin, urlStr))
	{
		try
		{
			CHttpUrl url(urlStr);
			std::cout << "URL: " << url.GetURL() << std::endl;
			std::cout << "Protocol: " << url.GetProtocol() << std::endl;
			std::cout << "Domain: " << url.GetDomain() << std::endl;
			std::cout << "Port: " << url.GetPort() << std::endl;
			std::cout << "Document: " << url.GetDocument() << std::endl;
		}
		catch (const CUrlParsingError& err)
		{
			std::cout << "Error: " << err.what() << std::endl;
		}
		catch (const std::invalid_argument& err)
		{
			std::cout << "Error: " << err.what() << std::endl;
		}
		catch (const std::out_of_range& err)
		{
			std::cout << "Error: " << err.what() << std::endl;
		}
		std::cout << "Enter url: " << "\n";
	} 
    return 0;
}

