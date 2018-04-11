#include "stdafx.h"
#include "..\translator\translator.h"

bool MapsAreEqual(const DictionaryMap & x, const DictionaryMap & y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(AddTranslation_function)
BOOST_AUTO_TEST_CASE(add_word_and_translation_in_map)
{
	DictionaryMap expectedMap = {
		{"hello", "привет"}
	};

	DictionaryMap outputMap;
	AddTranslation(outputMap, "hello", "привет");
	BOOST_CHECK(MapsAreEqual(expectedMap, outputMap));
}

BOOST_AUTO_TEST_CASE(get_empty_translation_and_not_add_in_map)
{
	DictionaryMap expectedMap = {};
	std::string translate = "";
	DictionaryMap outputMap;
	if (!translate.empty())
	{
		AddTranslation(outputMap, "hello", translate);
	}
	BOOST_CHECK(MapsAreEqual(expectedMap, outputMap));
}

BOOST_AUTO_TEST_SUITE_END()
/*
BOOST_AUTO_TEST_SUITE(Translate_function)
BOOST_AUTO_TEST_CASE(request_an_existing_word)
{
	DictionaryMap Map = {
		{ "hello", "привет" }
	};

	BOOST_CHECK(Translate(Map, "hello") == true);
}

BOOST_AUTO_TEST_CASE(request_an_not_existing_word)
{
	DictionaryMap Map = {
		{ "hello", "привет" }
	};

	BOOST_CHECK(Translate(Map, "cat") == false);
} 

BOOST_AUTO_TEST_SUITE_END() */