#include "stdafx.h"
#include "../Lab05/CRational.h"
bool equal(CRational & first, CRational & second)
{
	return (first.GetNumerator() == second.GetNumerator() and
		first.GetDenominator() == second.GetDenominator());
}

BOOST_AUTO_TEST_SUITE(make_new_rational)

BOOST_AUTO_TEST_CASE(without_argument)
{
	CRational el;
	BOOST_CHECK_EQUAL(el.GetNumerator(), 0);
}

BOOST_AUTO_TEST_CASE(with_one_argument)
{
	CRational el(2);
	BOOST_CHECK_EQUAL(el.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(el.GetDenominator(), 1);
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
	CRational el(0, 2);
	BOOST_CHECK_EQUAL(el.ToDouble(), 0.0);

	CRational newEl(1, 2);
	BOOST_CHECK_EQUAL(newEl.ToDouble(), 0.5);

	CRational zeroDenominator(2, 0);
	BOOST_CHECK_EQUAL(zeroDenominator.ToDouble(), 0.0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(unary_operators)
BOOST_AUTO_TEST_CASE(plus_dont_change_anything)
{
	CRational el(1, 2);
	BOOST_CHECK_EQUAL(+el.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(+el.GetDenominator(), 2);
}

BOOST_AUTO_TEST_CASE(minus_change_numerator)
{
	CRational el(1, 2);
	BOOST_CHECK_EQUAL((-el).GetNumerator(), -1);
	BOOST_CHECK_EQUAL((-el).GetDenominator(), 2);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(binary_operators)
BOOST_AUTO_TEST_CASE(plus_with_equal_denominators)
{
	CRational rv(1, 3);
	CRational lv(1, 3);
	CRational res = lv + rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(plus_with_int)
{
	CRational value(1, 2);
	CRational res = 1 + value;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 3);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 2);

	res = value + 1;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 3);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 2);

}

BOOST_AUTO_TEST_CASE(plus_with_not_equal_denominators)
{
	CRational rv(1, 3);
	CRational lv(1, 2);
	CRational res = lv + rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 5);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 6);
}

BOOST_AUTO_TEST_CASE(minus)
{
	CRational rv(2, 3);
	CRational lv(1, 3);
	CRational res = lv - rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), -1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(minus_with_int)
{
	CRational rv(2, 3);
	CRational res = 1 - rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(multiply)
{
	CRational rv(2, 3);
	CRational lv(1, 3);
	CRational res = lv * rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 9);
}

BOOST_AUTO_TEST_CASE(multiply_with_int)
{
	CRational value(2, 3);
	CRational res = value * 2;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);

	res = 2 * value;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 4);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);
}

BOOST_AUTO_TEST_CASE(division)
{
	CRational lv(2, 3);
	CRational rv(1, 3);
	CRational res = lv / rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 2);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 1);

	res = lv / 2;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 3);

	res = 2 / rv;
	BOOST_CHECK_EQUAL(res.GetNumerator(), 6);
	BOOST_CHECK_EQUAL(res.GetDenominator(), 1);
}

BOOST_AUTO_TEST_CASE(plus_equality)
{
	CRational value(2, 3);
	value += 1;
	BOOST_CHECK_EQUAL(value.GetNumerator(), 5);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(2, 3);
	CRational rvalue(1, 4);
	lvalue += rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), 11);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 12);
}

BOOST_AUTO_TEST_CASE(minus_equality)
{
	CRational value(2, 3);
	value -= 1;
	BOOST_CHECK_EQUAL(value.GetNumerator(), -1);
	BOOST_CHECK_EQUAL(value.GetDenominator(), 3);

	CRational lvalue(2, 3);
	CRational rvalue(1, 2);
	lvalue -= rvalue;
	BOOST_CHECK_EQUAL(lvalue.GetNumerator(), 1);
	BOOST_CHECK_EQUAL(lvalue.GetDenominator(), 6);
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

BOOST_AUTO_TEST_CASE(equality)
{
	CRational value(2, 3);
	CRational copyValue(2, 3);
	BOOST_CHECK_EQUAL(value, copyValue);
}

BOOST_AUTO_TEST_CASE(not_equality)
{
	CRational value(2, 3);
	CRational copyValue(2, 3);
	BOOST_CHECK_EQUAL(value, copyValue);
}

BOOST_AUTO_TEST_CASE(greater)
{
	CRational lvalue(2, 3);
	CRational rvalue(1, 3);
	BOOST_CHECK(lvalue != rvalue);
}

BOOST_AUTO_TEST_CASE(less)
{
	CRational lvalue(1, 3);
	CRational rvalue(2, 3);
	BOOST_CHECK(lvalue < rvalue);
}

BOOST_AUTO_TEST_CASE(less_or_equal)
{
	CRational lvalue(-1, 3);
	CRational rvalue(1, 3);
	BOOST_CHECK(lvalue <= rvalue);
	BOOST_CHECK(lvalue <= 0);
}

BOOST_AUTO_TEST_CASE(greater_or_equal)
{
	CRational lvalue(4, 3);
	CRational rvalue(1, 3);
	BOOST_CHECK(lvalue >= 1);
}

BOOST_AUTO_TEST_SUITE_END()