#include "stdafx.h"
#include "CRational.h"
#include <iostream>
#include <numeric>

//  онструирует рациональное число, равное нулю (0/1)
CRational::CRational()
	: m_numerator(0)
	, m_denominator(1)
{
}

//  онструирует рациональное число, равное value (value/1)
CRational::CRational(int value)
	: m_numerator(value)
	, m_denominator(1)
{
}

//  онструирует рациональное число, равное numerator/denominator
// –ациональное число должно хранитьс€ в нормализованном виде:
// знаменатель положительный (числитель может быть отрицательным)
// числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю,
// либо должно быть выброшено исключение std::invalid_argument.
CRational::CRational(int numerator, int denominator)
{
	if (denominator <= 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	else
	{
		m_numerator = numerator;
		m_denominator = denominator;
		ReduceFraction(*this);
	}
}

void CRational::ReduceFraction(CRational& rational)
{
	int nod = std::gcd(rational.m_numerator, rational.m_denominator);
	rational.m_numerator /= nod;
	rational.m_denominator /= nod;
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

// ¬озвращает знаменатель (натуральное число)
int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return double(m_numerator) / double(m_denominator);
}

const CRational& operator+(const CRational& rvalue)
{
	return (rvalue);
}

const CRational operator-(const CRational& rvalue)
{
	return CRational(-rvalue.m_numerator, rvalue.m_denominator);
}

const CRational operator+(const CRational& lvalue, const CRational& rvalue)
{
	auto rcopy = rvalue;
	auto lcopy = lvalue;
	return lcopy += rcopy;
}

const CRational operator-(const CRational& lvalue, const CRational& rvalue)
{
	return lvalue + (-rvalue);
}

const CRational operator*(const CRational& lvalue, const CRational& rvalue)
{
	auto rcopy = rvalue;
	auto lcopy = lvalue;
	return lcopy *= rcopy;
}

const CRational operator/(const CRational& lvalue, const CRational& rvalue)
{
	auto rcopy = rvalue;
	auto lcopy = lvalue;
	return lcopy /= rcopy;
}

const CRational CRational::operator+=(const CRational& value)
{
	if (m_denominator == value.m_denominator)
	{
		CRational result(m_numerator + value.m_numerator, m_denominator);
		return result;
	}

	int newDenominator = std::lcm(m_denominator, value.m_denominator);
	int lMultiplier = newDenominator / m_denominator;
	int rMultiplier = newDenominator / value.m_denominator;

	m_denominator = newDenominator;
	m_numerator = m_numerator * lMultiplier + value.m_numerator * rMultiplier;

	ReduceFraction(*this);
	return *this;
}

const CRational CRational::operator-=(const CRational& value)
{
	return *this += -value;
}

const CRational CRational::operator*=(const CRational& value)
{

	CRational firstMultiplier(m_numerator, value.m_denominator);
	CRational secondMultiplier(value.m_numerator, m_denominator);

	CRational storage(firstMultiplier.m_numerator * secondMultiplier.m_numerator,
		firstMultiplier.m_denominator * secondMultiplier.m_denominator);

	return *this = storage;
}

const CRational CRational::operator/=(const CRational& value)
{
	CRational firstMultiplier(m_numerator, value.m_numerator);
	CRational secondMultiplier(value.m_denominator, m_denominator);

	CRational storage(firstMultiplier.m_numerator * secondMultiplier.m_numerator, 
		firstMultiplier.m_denominator * secondMultiplier.m_denominator);

	return *this = storage;
}

bool operator==(const CRational& lvalue, const CRational& rvalue)
{
	return (lvalue.m_numerator == rvalue.m_numerator and lvalue.m_denominator == rvalue.m_denominator);
}

bool operator!=(const CRational& lvalue, const CRational& rvalue)
{
	return !(lvalue == rvalue);
}

bool operator<(const CRational& lvalue, const CRational& rvalue)
{
	int newDenominator = std::lcm(lvalue.m_denominator, rvalue.m_denominator);
	int lMultiplier = newDenominator / lvalue.m_denominator;
	int rMultiplier = newDenominator / rvalue.m_denominator;

	return (lvalue.m_numerator*lMultiplier < rvalue.m_numerator*rMultiplier);
}

bool operator>(const CRational& lvalue, const CRational& rvalue)
{
	return rvalue < lvalue;
}

bool operator<=(const CRational& lvalue, const CRational& rvalue)
{
	return !(lvalue > rvalue);
}
bool operator>=(const CRational& lvalue, const CRational& rvalue)
{
	return !(lvalue < rvalue);
}

std::ostream& operator<<(std::ostream& output, const CRational& value)
{
	if (value.GetNumerator() == value.GetDenominator())
	{
		output << 1;
	}
	else if (value.GetNumerator() == 0)
	{
		output << 0;
	}
	else if (value.GetDenominator() == 1)
	{
		output << value.GetNumerator();
	}
	else
	{
		output << value.GetNumerator() << "/" << value.GetDenominator();
	}

	return output;
}
