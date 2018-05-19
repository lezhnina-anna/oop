#include "stdafx.h"
#include "LineSegment.h"
#include <cmath>
#include <string>

CLineSegment::CLineSegment(CPoint &first, CPoint &second, const std::string& color)
    : m_startPoint(first)
	, m_endPoint(second) 
{
	SetOutlineColor(color);
}

double CLineSegment::GetArea() const
{ 
	return 0; 
}

double CLineSegment::GetPerimeter() const 
{ 
	return sqrt(pow((m_endPoint.x - m_startPoint.x), 2)
		+ pow((m_endPoint.y - m_startPoint.y), 2));
}

void CLineSegment::AppendProperties(std::ostream & strm) const
{
	std::string info = "Shape Type : Line\n";
	info += "Start Point: " + m_startPoint.ToString()
		+ "\nEnd Point is: " + m_endPoint.ToString()
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: 0";
	strm << info << std::endl;
}
CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

void CLineSegment::SetStartPoint(CPoint startPoint) 
{
	m_startPoint = startPoint;
}

void CLineSegment::SetEndPoint(CPoint endPoint)
{
	m_endPoint = endPoint;
}
