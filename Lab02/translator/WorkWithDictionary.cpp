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

bool AskToTranslation(const std::string &wordToTranslate, std::string& translation)
{
	std::cout << "Неизвестное слово " << wordToTranslate << ". Введите перевод или пустую строку для отказа."
			  << "\n";

	getline(std::cin, translation);

	if (translation.empty())
	{
		std::cout << "Слово " << wordToTranslate << " проигнорировано.\n";
		return false;
	}

	return true;
}

void AddTranslation(DictionaryMap& dictionary, const std::string & wordToTranslate, const std::string & translation)
{
	dictionary.insert(std::pair<std::string, std::string>(wordToTranslate, translation));
	std::cout << "Слово " << wordToTranslate << " сохранено в словаре как " << translation << "\n";
}

bool ProcessDataWithChanges(DictionaryMap& dictionary)
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

bool NeedToSave()
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
	return false;
}
