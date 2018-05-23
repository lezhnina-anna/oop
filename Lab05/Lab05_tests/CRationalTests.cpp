#include "stdafx.h"
#include "../Lab05/CRational.h"

BOOST_AUTO_TEST_SUITE(make_new_rational)

BOOST_AUTO_TEST_CASE(without_argument)
{
	CRational el;
	BOOST_CHECK_EQUAL(el.GetNumerator(), 0);
}

BOOST_AUTO_TEST_CASE(with_one_argument)
{
	BOOST_CHECK_EQUAL(CRational(2).GetNumerator(), 2);
	BOOST_CHECK_EQUAL(CRational(2).GetDenominator(), 1);
}

BOOST_AUTO_TEST_CASE(with_two_argument)
{
	CRational el(1,8);
	BOOST_CHECK_EQUAL(el.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(el.GetDenominator(), 8);

	//c сокращением
	CRational newEl(2, 8);
	BOOST_CHECK_EQUAL(newEl.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(newEl.GetDenominator(), 4);

	//c нулевым знаменателем
	CRational zeroDenominator(2, 0);
	BOOST_CHECK_EQUAL(zeroDenominator.GetNumerator(), 0);
	BOOST_CHECK_EQUAL(zeroDenominator.GetDenominator(), 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(to_double)
BOOST_AUTO_TEST_CASE(check)
{
	BOOST_CHECK_EQUAL(CRational(0, 2).ToDouble(), 0.0);
	BOOST_CHECK_EQUAL(CRational(1, 2).ToDouble(), 0.5);
	BOOST_CHECK_EQUAL(CRational(2, 0).ToDouble(), 0.0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(unary_operators)
CRational el(1, 2);
BOOST_AUTO_TEST_CASE(plus_dont_change_anything)
{
	BOOST_CHECK_EQUAL((+el).GetNumerator(), 1);
	BOOST_CHECK_EQUAL((+el).GetDenominator(), 2);
}

BOOST_AUTO_TEST_CASE(minus_change_numerator)
{
	BOOST_CHECK_EQUAL((-el).GetNumerator(), -1);
	BOOST_CHECK_EQUAL((-el).GetDenominator(), 2);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(binary_operators)
BOOST_AUTO_TEST_CASE(plus_with_equal_denominators)
{
	CRational res = CRational(1, 3) + CRational(1, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(plus_with_int)
{
	CRational res = CRational(1, 2) + 1;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 3);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 2);

	res = 1 + CRational(1, 2);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 3);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 2);

}

BOOST_AUTO_TEST_CASE(plus_with_not_equal_denominators)
{
	CRational res = CRational(1, 6) + CRational(1, 2);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(minus)
{
	CRational res = CRational(2, 3) - CRational(1, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);

	res = CRational(1, 2) - CRational(1, 6);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(minus_with_int)
{
	CRational res = 1 - CRational(2, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(multiply)
{
	CRational res = CRational(2, 5) * CRational(1, 10);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 25);
}

BOOST_AUTO_TEST_CASE(multiply_with_int)
{
	CRational res = CRational(2, 3) * 2;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);

	res = 2 * CRational(2, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(division)
{
	CRational res = CRational(2, 3) / CRational(1, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 1);

	res = CRational(2, 3) / 2;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);

	res = 2 / CRational(1, 3);
	BOOST_CHECK_EQUAL(res.GetNumerator(), 6);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 1);
}

BOOST_AUTO_TEST_CASE(plus_equality)
{
	CRational value(2, 3);
	value += 1;
	BOOST_CHECK_EQUAL(value.GetNumerator(), 5);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(1, 6);
	CRational rvalue(1, 2);
	lvalue += rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(minus_equality)
{
	CRational value(2, 3);
	value -= 1;
	BOOST_CHECK_EQUAL(value.GetNumerator(), -1);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(1, 4);
	CRational rvalue(1, 3);
	lvalue -= rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), -1);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 12);
}

BOOST_AUTO_TEST_CASE(multiply_equality)
{
	CRational value(2, 3);
	value *= 2;
	BOOST_CHECK_EQUAL(value.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(2, 3);
	CRational rvalue(1, 2);
	lvalue *= rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(division_equality)
{
	CRational value(2, 3);
	value /= 2;
	BOOST_CHECK_EQUAL(value.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(2, 3);
	CRational rvalue(1, 2);
	lvalue /= rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 3);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(bool_operators)

BOOST_AUTO_TEST_CASE(equality_and_not_equality)
{
	CRational value(2, 3);
	CRational copyValue(2, 3);
	BOOST_CHECK_EQUAL(value, copyValue);
	BOOST_CHECK(!(value == 3));
	BOOST_CHECK(value != CRational(1, 9));
	BOOST_CHECK(!(value != copyValue));

}

BOOST_AUTO_TEST_CASE(greater)
{
	CRational lvalue(2, 3);
	CRational rvalue(1, 3);
	BOOST_CHECK(lvalue > rvalue);
	BOOST_CHECK(!(rvalue > lvalue));
	BOOST_CHECK(!(CRational(1, 3) > CRational(1, 3)));
}

BOOST_AUTO_TEST_CASE(less)
{
	CRational lvalue(1, 3);
	CRational rvalue(2, 3);
	BOOST_CHECK(lvalue < rvalue);
	BOOST_CHECK(!(rvalue < lvalue));
	BOOST_CHECK(!(CRational(1, 3) < CRational(1, 3)));
}

BOOST_AUTO_TEST_CASE(less_or_equal)
{
	BOOST_CHECK(CRational(-1, 3) <= 0);
	BOOST_CHECK(!(CRational(1, 3) <= 0));
	BOOST_CHECK_LE(CRational(-1, 3), CRational(1, 3));
	BOOST_CHECK_LE(CRational(1, 3), CRational(1, 3));
}

BOOST_AUTO_TEST_CASE(greater_or_equal)
{
	BOOST_CHECK_GE(CRational(4, 3), 1);
	BOOST_CHECK_GE(CRational(4, 3), CRational(4, 3));
	BOOST_CHECK(!(CRational(4, 3) >= CRational(5, 3)));
}

BOOST_AUTO_TEST_CASE(print)
{
	std::ostringstream strm;
	strm << CRational(2, 1) << ", " << CRational(2, 2) << ", " << CRational(2, 0) 
		<< ", " << CRational(1, 3);
	BOOST_CHECK_EQUAL(strm.str(), "2, 1, 0, 1/3");
}


BOOST_AUTO_TEST_SUITE_END()