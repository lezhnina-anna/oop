#include "stdafx.h"
#include "FindAndReplace.h"
#include <string>

std::string FindAndReplace(std::string text, const std::string stringToSearch, std::string stringToReplace)
{
	if (!stringToSearch.empty())
	{
		size_t position = 0;

		while ((position = text.find(stringToSearch, position)) != std::string::npos)
		{
			text.replace(position, stringToSearch.length(), stringToReplace);
			position += stringToReplace.length();
		}
	}

	return text;
}
