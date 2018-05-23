#include "stdafx.h"
#include "UrlParsingError.h"
#include <string>
#include <iostream>

CUrlParsingError::CUrlParsingError(const std::string & info) : std::invalid_argument(info)
{
	std::cout << info << std::endl;
}
