// translator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <windows.h>;

bool Translate(const std::map <std::string, std::string> & dictionary, const std::string wordToTranslate)
{
	auto position = dictionary.find(wordToTranslate);

	if (position != dictionary.end())
	{
		std::cout << position->second << "\n";
		return true;
	}

	return false;
}

bool AskToTranslation(const std::string wordToTranslate, std::string & translation)
{
	std::cout << "Неизвестное слово """ << wordToTranslate << """ Введите перевод или пустую строку для отказа." << "\n";

    getline(std::cin, translation);

	if (translation.empty())
	{
		std::cout << "Слово """ << wordToTranslate << """ проигнорировано.\n";
		return false;
	}

	return true;
}

void AddTranslation(std::map <std::string, std::string> & dictionary, const std::string wordToTranslate, const std::string translation)
{
	dictionary.insert(std::pair<std::string, std::string>(wordToTranslate, translation));
	std::cout << "Слово """ << wordToTranslate << """ сохранено в словаре как """ << translation << "\n";
}

bool FillDictionary(std::string fileName, std::map <std::string, std::string> & dictionary)
{
	std::ifstream dictionaryFile(fileName);

	if (!dictionaryFile.is_open())
	{
		std::cout << "Error: Failed to open " << fileName << ". A new file was created\n";
		return false;
	}

	std::string str;

	while (getline(dictionaryFile, str))
	{
		std::size_t pos = str.find("*");
		std::string engWord = str.substr(0, pos);
		std::string rusWord = str.substr(pos + 1);
		dictionary.insert(std::pair<std::string, std::string>(engWord, rusWord));
	}

	return true;
}

bool ProcessDataWithChanges(std::map <std::string, std::string> & dictionary)
{
	//взаимодействие с пользователем 

	std::string EXIT = "...";
	bool changes = false;
	std::string wordToTranslate;

	while (getline(std::cin, wordToTranslate) && wordToTranslate != EXIT)
	{
		if (!Translate(dictionary, wordToTranslate))
		{
			std::string translation;

			if (AskToTranslation(wordToTranslate, translation))
			{
				AddTranslation(dictionary, wordToTranslate, translation);
				changes = true;
			}
		}
	}

	return changes;
}

bool NeedToSave(std::map <std::string, std::string> & dictionary)
{
	if (ProcessDataWithChanges(dictionary))
	{
		std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";

		std::string answer;

		getline(std::cin, answer);

		if ((answer == "y") || (answer == "Y"))
		{
			return true;
		}
		else
		{
			std::cout << "Изменения не сохранены. До свидания." << std::endl;
		}
	}

	return false;
}

void UpdateDictionaryFile(std::map <std::string, std::string> & dictionary, std::string fileName)
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
	std::map <std::string, std::string> dictionary;

	if (argc > 2)
	{
		std::cout << "Error: Invalid arguments count." << std::endl;
		return 1;
	}
	else if (argc == 2)
	{
		std::string fileName = argv[1];
		FillDictionary(fileName, dictionary);
	}

	if (NeedToSave(dictionary))
	{
		UpdateDictionaryFile(dictionary, fileName);
	}

    return 0;
}



