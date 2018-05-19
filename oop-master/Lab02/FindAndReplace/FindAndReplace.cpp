#include "stdafx.h"
#include "FindAndReplace.h"
#include <string>

std::string FindAndReplace(const std::string & text, const std::string & stringToSearch, const std::string & stringToReplace)
{
	if (!stringToSearch.empty())
	{
		size_t position = 0;
		size_t ñopyPosition = 0;
		std::string textWithReplaces;

		while ((position = text.find(stringToSearch, position)) != std::string::npos)
		{
			textWithReplaces.append(text, ñopyPosition, position - ñopyPosition);
			textWithReplaces.append(stringToReplace);
			position += stringToSearch.length();
			ñopyPosition = position;
		}

		textWithReplaces.append(text, ñopyPosition, text.length() - ñopyPosition);

		return textWithReplaces;
	}

	return text;
}
