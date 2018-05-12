#include "stdafx.h"
#include "CPoint.h"
// #include <sstream>

CPoint::CPoint(double x, double y)
	: x(x)
	, y(y)
{
}

std::string CPoint::ToString() const
{
	std::string info;
	info = "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
	return info;
}

bool operator==(CPoint left, CPoint right)
{
	return (left.x == right.x && left.y == right.y) ? true : false;
}

std::istream& operator>>(std::istream& in, CPoint& value)
{
	double x = 0, y = 0;
	in >> x >> y;
	value.x = x;
	value.y = y;

	return in;
}