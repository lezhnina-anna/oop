#pragma once
#include <stdexcept>
// #include <string>

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string & info);
};
