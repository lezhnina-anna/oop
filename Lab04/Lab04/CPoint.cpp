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
