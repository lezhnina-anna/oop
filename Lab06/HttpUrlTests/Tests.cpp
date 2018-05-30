#include "stdafx.h"
#include "../Lab06/HttpUrl.h"
#include "../Lab06/UrlParsingError.h"


BOOST_AUTO_TEST_SUITE(url_string_representation)
BOOST_AUTO_TEST_CASE(no_throw_without_document)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("http://vk.com/"));
}
BOOST_AUTO_TEST_CASE(no_throw_without_port)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("http://vk.com/qwerty"));
}
BOOST_AUTO_TEST_CASE(no_throw_with_correct_port)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("https://vk.com:36"));
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:0"), CUrlParsingError);
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:700000"), CUrlParsingError);
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:q"), CUrlParsingError);
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_document)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com/qwer ty"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_protocol)
{
	BOOST_REQUIRE_THROW(CHttpUrl("httpp://vk.com/qwerty"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk. com/qwerty"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_syntax)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http:///vk.com/qwerty"), CUrlParsingError);
	BOOST_REQUIRE_THROW(CHttpUrl("http:/vk.com/qwerty"), CUrlParsingError);
	BOOST_REQUIRE_THROW(CHttpUrl("http:vk.com/qwerty"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_empty_url)
{
	BOOST_REQUIRE_THROW(CHttpUrl(""), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_with_empty_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://"), CUrlParsingError);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(make_correct_url)
BOOST_AUTO_TEST_CASE(with_standart_port)
{
	CHttpUrl url("http://localhost/phpmyadmin/db_structure.php");

	BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost/phpmyadmin/db_structure.php");
	BOOST_CHECK_EQUAL(url.GetProtocol(), Protocol::HTTP);
	BOOST_CHECK_EQUAL(url.GetDomain(), "localhost");
	BOOST_CHECK_EQUAL(url.GetPort(), 80);
	BOOST_CHECK_EQUAL(url.GetDocument(), "/phpmyadmin/db_structure.php");
	
}
BOOST_AUTO_TEST_CASE(with_user_port)
{
	CHttpUrl url("http://localhost:3030/phpmyadmin/db_structure.php");

	BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost:3030/phpmyadmin/db_structure.php");
	BOOST_CHECK_EQUAL(url.GetPort(), 3030);

}
BOOST_AUTO_TEST_CASE(without_document)
{
	CHttpUrl url("http://localhost");

	BOOST_CHECK_EQUAL(url.GetDocument(), "/");
	BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost/");

}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(url_parse_with_arguments)
BOOST_AUTO_TEST_CASE(no_throw_with_correct_arguments)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("vk.com", "/qwerty", Protocol::HTTP));
}
BOOST_AUTO_TEST_CASE(no_throw_without_document)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("vk.com", "", Protocol::HTTP, 80));
}
BOOST_AUTO_TEST_CASE(throw_with_empty_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("", "", Protocol::HTTP, 80), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(no_throw_without_port)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("vk.com", "/qwerty", Protocol::HTTP));
}
BOOST_AUTO_TEST_CASE(no_throw_with_correct_port)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("vk.com", "/qwerty", Protocol::HTTP, 30));
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl("vk.com", "/qwerty", Protocol::HTTP, 0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_document)
{
	BOOST_REQUIRE_THROW(CHttpUrl("vk.com", "/qwe rty", Protocol::HTTP), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(throw_with_incorrect_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("vk . com", "/qwerty", Protocol::HTTP), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(make_correct_url)
{
	CHttpUrl url("localhost", "/phpmyadmin/db_structure.php", Protocol::HTTP);

	BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost/phpmyadmin/db_structure.php");
	BOOST_CHECK_EQUAL(url.GetProtocol(), Protocol::HTTP);
	BOOST_CHECK_EQUAL(url.GetDomain(), "localhost");
	BOOST_CHECK_EQUAL(url.GetPort(), 80);
	BOOST_CHECK_EQUAL(url.GetDocument(), "/phpmyadmin/db_structure.php");

}
BOOST_AUTO_TEST_CASE(check_bound_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:0"), CUrlParsingError);
	BOOST_REQUIRE_NO_THROW(CHttpUrl("http://vk.com:1"));
	BOOST_REQUIRE_THROW(CHttpUrl("http://vk.com:65536"), CUrlParsingError);
	BOOST_REQUIRE_NO_THROW(CHttpUrl("http://vk.com:65535"));
}
BOOST_AUTO_TEST_SUITE_END()
