#include "stdafx.h"
#include "CTriangle.h"

double getSideLen(const CPoint & v1, const CPoint & v2)
{
	return sqrt(pow((v1.x - v2.x), 2)
		+ pow((v1.y - v2.y), 2));
}

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, const std::string & fillColor, const std::string& outlineColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter()/2;
	double a = getSideLen(m_vertex1, m_vertex2);
	double b = getSideLen(m_vertex2, m_vertex3);
	double c = getSideLen(m_vertex3, m_vertex1);

	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double CTriangle::GetPerimeter() const
{
	double perimeter = getSideLen(m_vertex1, m_vertex2) 
		+ getSideLen(m_vertex2, m_vertex3)
		+ getSideLen(m_vertex3, m_vertex1);

	return perimeter;
}

std::string CTriangle::ToString() const
{
	std::string info = "Shape Type : Triangle\n";
	info += "First Vertex: " + m_vertex1.ToString()
		+ "\nSecond Vertex: " + m_vertex2.ToString()
		+ "\nThird Vertex: " + m_vertex3.ToString()
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea())
		+ "\nOutline Color: " + CShape::GetOutlineColor()
		+ "\nFill Color: " + GetFillColor();
	return info;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::SetVertex1(CPoint vertex)
{
	m_vertex1 = vertex;
}

void CTriangle::SetVertex2(CPoint vertex)
{
	m_vertex2 = vertex;
}

void CTriangle::SetVertex3(CPoint vertex)
{
	m_vertex3 = vertex;
}