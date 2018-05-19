#pragma once
#include <iostream>

class CRational

{
public:
	// ������������ ������������ �����, ������ ���� (0/1)
	CRational();

	// ������������ ������������ �����, ������ value (value/1)
	CRational(int value);

	// ������������ ������������ �����, ������ numerator/denominator
	// ������������ ����� ������ ��������� � ��������������� ����:
	// ����������� ������������� (��������� ����� ���� �������������)
	// ��������� � ����������� �� ����� ����� ��������� (6/8 => 3/4 � �.�.)
	// ���� ����������� ����� ����, ������ ����������������� ������������ �����, ������ ����,
	// ���� ������ ���� ��������� ���������� std::invalid_argument.
	CRational(int numerator, int denominator);

	// ���������� ���������
	int GetNumerator() const;

	// ���������� ����������� (����������� �����)
	int GetDenominator() const;

	// ���������� ��������� ��������� � ����������� � ���� ����� double
	double ToDouble() const;

	// ������ ��������� �������� �������
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
