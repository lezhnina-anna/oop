// translator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "translator.h"

bool FillDictionaryMap(const std::string fileName, DictionaryMap& dictionary)
{
	std::ifstream dictionaryFile(fileName);

	if (!dictionaryFile.is_open())
	{
		std::cout << "Error: Failed to open " << fileName << "\n";
		return false;
	}

	std::string wordAndTranslation;

	while (getline(dictionaryFile, wordAndTranslation))
	{
		std::size_t pos = wordAndTranslation.find("*");
		std::string engWord = wordAndTranslation.substr(0, pos);
		std::string rusWord = wordAndTranslation.substr(pos + 1);
		dictionary.insert(std::pair<std::string, std::string>(engWord, rusWord));
	}

	return true;
}

void UpdateDictionaryFile(DictionaryMap& dictionary, const std::string fileName)
{
	std::ofstream dictionaryFile(fileName);

	if (dictionaryFile.is_open())
	{
		for (auto words : dictionary)
		{
			dictionaryFile << words.first << "*" << words.second << "\n";
		}

		dictionaryFile.flush() ? std::cout << "Изменения сохранены. До свидания." << std::endl : std::cout << "Failed to save data on disk" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2)
	{
		std::cout << "Error: Invalid arguments count." << std::endl;
		return 1;
	}

	DictionaryMap dictionary;
	std::string fileName = argv[1];

	FillDictionaryMap(fileName, dictionary);
	if (ProcessDataWithChanges(dictionary))
	{
		if (NeedToSave())
		{
			UpdateDictionaryFile(dictionary, fileName);
		}
	}
	
	return 0;
}
