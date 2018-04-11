#pragma once
#include "stdafx.h"

using DictionaryMap = std::map <std::string, std::string>;
bool NeedToSave();
bool ProcessDataWithChanges(DictionaryMap & dictionary);
void AddTranslation(DictionaryMap & dictionary, const std::string & wordToTranslate, const std::string & translation);
bool AskToTranslation(const std::string & wordToTranslate, std::string & translation);
bool Translate(const DictionaryMap & dictionary, const std::string & wordToTranslate);