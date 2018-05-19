#include "stdafx.h"

bool Translate(const DictionaryMap& dictionary, const std::string& wordToTranslate)
{
	auto position = dictionary.find(wordToTranslate);

	if (position != dictionary.end())
	{
		std::cout << position->second << "\n";
		return true;
	}

	return false;
}

bool AskForTranslation(const std::string& wordToTranslate, std::string& translation)
{
	std::cout << "����������� ����� " << wordToTranslate << ". ������� ������� ��� ������ ������ ��� ������."
			  << "\n";

	getline(std::cin, translation);

	if (translation.empty())
	{
		std::cout << "����� " << wordToTranslate << " ���������������.\n";
		return false;
	}

	return true;
}

void AddTranslation(DictionaryMap& dictionary, const std::string& wordToTranslate, const std::string& translation)
{
	dictionary.emplace(std::make_pair(wordToTranslate, translation));
	std::cout << "����� " << wordToTranslate << " ��������� � ������� ��� " << translation << "\n";
}

bool InteractionWithUser(DictionaryMap& dictionary)
{
	//�������������� � �������������
	std::string EXIT = "...";
	bool changes = false;
	std::string wordToTranslate;

	while (getline(std::cin, wordToTranslate) && wordToTranslate != EXIT)
	{
		if (!Translate(dictionary, wordToTranslate))
		{
			std::string translation;

			if (AskForTranslation(wordToTranslate, translation))
			{
				AddTranslation(dictionary, wordToTranslate, translation);
				changes = true;
			}
		}
	}

	return changes;
}

bool NeedToSave()
{
	std::cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";

	std::string answer;

	getline(std::cin, answer);

	if ((answer == "y") || (answer == "Y"))
	{
		return true;
	}
	else
	{
		std::cout << "��������� �� ���������. �� ��������." << std::endl;
	}
	return false;
}
