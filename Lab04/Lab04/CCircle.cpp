#include "stdafx.h"
#include "CCircle.h"

const double PI = 3.14159265;

CCircle::CCircle(CPoint center, double radius, const std::string & fillColor, const std::string& outlineColor)
	: m_center(center)
	, m_radius(radius)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}

double CCircle::GetArea() const
{
	return (PI*m_radius*m_radius);
}

double CCircle::GetPerimeter() const
{
	return (2 * PI*m_radius);
}

std::string CCircle::ToString() const
{
	std::string info = "Shape Type : Circle\n";
	info += "Center: " + m_center.ToString()
		+ "\nRadius: " + std::to_string(m_radius)
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea())
		+ "\nOutline Color: " + CShape::GetOutlineColor()
		+ "\nFill Color: " + GetFillColor();
	return info;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::SetCenter(CPoint center)
{
	m_center = center;
}

void CCircle::SetRadius(double radius)
{
	m_radius = radius;
}