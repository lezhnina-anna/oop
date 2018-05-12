#pragma once

#include <iostream>
#include <string>

class CPoint
{
public:
	class CPoint(double x, double y);
	std::string ToString() const;

	double x;
	double y;
};

bool operator==(CPoint left, CPoint right);
std::istream& operator>>(std::istream&, CPoint&);