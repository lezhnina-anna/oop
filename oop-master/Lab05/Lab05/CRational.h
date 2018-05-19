#pragma once
#include <iostream>

class CRational

{
public:
	//  онструирует рациональное число, равное нулю (0/1)
	CRational();

	//  онструирует рациональное число, равное value (value/1)
	CRational(int value);

	//  онструирует рациональное число, равное numerator/denominator
	// –ациональное число должно хранитьс€ в нормализованном виде:
	// знаменатель положительный (числитель может быть отрицательным)
	// числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
	// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю,
	// либо должно быть выброшено исключение std::invalid_argument.
	CRational(int numerator, int denominator);

	// ¬озвращает числитель
	int GetNumerator() const;

	// ¬озвращает знаменатель (натуральное число)
	int GetDenominator() const;

	// ¬озвращает отношение числител€ и знаменател€ в виде числа double
	double ToDouble() const;

	// ѕрочие операторы согласно заданию
	friend const CRational& operator+(const CRational& rvalue);
	friend const CRational operator-(const CRational& rvalue);

	friend const CRational operator+(const CRational& lvalue, const CRational& rvalue);
	friend const CRational operator-(const CRational& lvalue, const CRational& rvalue);
	friend const CRational operator*(const CRational& lvalue, const CRational& rvalue);
	friend const CRational operator/(const CRational& lvalue, const CRational& rvalue);

	const CRational operator+=(const CRational& value);
	const CRational operator-=(const CRational& value);
	const CRational operator*=(const CRational& value);
	const CRational operator/=(const CRational& value);
	
	friend bool operator==(const CRational& lvalue, const CRational& rvalue);
	friend bool operator!=(const CRational& lvalue, const CRational& rvalue);
	friend bool operator<(const CRational& lvalue, const CRational& rvalue);
	friend bool operator>(const CRational& lvalue, const CRational& rvalue);
	friend bool operator<=(const CRational& lvalue, const CRational& rvalue);
	friend bool operator>=(const CRational& lvalue, const CRational& rvalue);
	
	friend std::ostream& operator<<(std::ostream& output, const CRational& value);
	/*friend std::istream& operator>>(std::istream& input, CRational& value);*/
private:
	int m_numerator, m_denominator;
	void ReduceFraction(CRational & rational);
};
