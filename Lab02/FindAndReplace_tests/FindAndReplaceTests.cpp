#include "stdafx.h"
#include "..\FindAndReplace\FindAndReplace.h"

bool StringsAreEqual(std::string const& x, std::string const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

	BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_string)
	{
		std::string search = "hello";
		std::string replace = "world";
		std::string inputString = "";
		std::string outputString = FindAndReplace(inputString, search, replace);
		BOOST_CHECK(outputString.empty());
	}

	// Искомая строка является пустой
	BOOST_AUTO_TEST_SUITE(when_searched_string_is_empty)
        //не изменяет содержимое входной строки
		BOOST_AUTO_TEST_CASE(does_not_change_input_string)
		{
			std::string search = "";
			std::string replace = "hello";
			std::string inputString = "hello world!";
			std::string outputString = FindAndReplace(inputString, search, replace);
			BOOST_CHECK(StringsAreEqual(inputString, outputString));
        }
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_replaced_string_is_empty)
   
		BOOST_AUTO_TEST_CASE(delete_searched_string)
            {
				std::string search = "hello";
				std::string replace = "";
				std::string inputString = "hello world!";
				std::string expectedOutputString = " world!";
				std::string outputString = FindAndReplace(inputString, search, replace);
				BOOST_CHECK(StringsAreEqual(expectedOutputString, outputString));
            }
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()