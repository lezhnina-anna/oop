// translator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "translator.h"


bool FillDictionaryMap(const std::string fileName, DictionaryMap & dictionary)
{
	std::ifstream dictionaryFile(fileName);

	if (!dictionaryFile.is_open())
	{
		std::cout << "Error: Failed to open " << fileName << ". A new file was created\n";
		return false;
	}

	std::string pair;

	while (getline(dictionaryFile, pair))
	{
		std::size_t pos = pair.find("*");
		std::string engWord = pair.substr(0, pos);
		std::string rusWord = pair.substr(pos + 1);
		dictionary.insert(std::pair<std::string, std::string>(engWord, rusWord));
	}

	return true;
}


void UpdateDictionaryFile(DictionaryMap & dictionary, const std::string fileName)
{
	std::ofstream dictionaryFile(fileName);

	if (dictionaryFile.is_open())
	{
		for (auto words : dictionary)
		{
			dictionaryFile << words.first << "*" << words.second << "\n";
		}

		dictionaryFile.flush() ? std::cout << "Изменения сохранены. До свидания." << std::endl : 
			std::cout << "Failed to save data on disk" << std::endl;

	}
}

int main(int argc, char * argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fileName = "NewDictionaryFile.txt";
	DictionaryMap dictionary;

	if (argc > 2)
	{
		std::cout << "Error: Invalid arguments count." << std::endl;
		return 1;
	}
	else if (argc == 2)
	{
		std::string fileName = argv[1];
		FillDictionaryMap(fileName, dictionary);
	}

	if (NeedToSave(dictionary))
	{
		UpdateDictionaryFile(dictionary, fileName);
	}

    return 0;
}



