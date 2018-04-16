#include "stdafx.h"
#include "FindAndReplace.h"
#include <string>

std::string FindAndReplace(const std::string & text, const std::string & stringToSearch, const std::string & stringToReplace)
{
	if (!stringToSearch.empty())
	{
		size_t position = 0;
		size_t �opyPosition = 0;
		std::string textWithReplaces;

		while ((position = text.find(stringToSearch, position)) != std::string::npos)
		{
			textWithReplaces.append(text, �opyPosition, position - �opyPosition);
			textWithReplaces.append(stringToReplace);
			position += stringToSearch.length();
			�opyPosition = position;
		}

		textWithReplaces.append(text, �opyPosition, text.length() - �opyPosition);

		return textWithReplaces;
	}

	return text;
}
