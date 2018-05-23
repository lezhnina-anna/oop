#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTop, double width, double height, const std::string& fillColor, const std::string& outlineColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter() const
{
	return 2*(m_height+m_width);
}

void CRectangle::AppendProperties(std::ostream & strm) const
{
	std::string info = "Shape Type : Rectangle\n";
	info += "Left Top Vertex: " + m_leftTop.ToString()
		+ "\nRight Bottom Vertex: " + GetRightBottom().ToString()
		+ "\nWidth: " + std::to_string(GetWidth())
		+ "\nHeight: " + std::to_string(GetHeight())
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea());
	strm << info << std::endl;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rightBottom(m_leftTop.x + m_width, m_leftTop.y - m_height);
	return rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetLeftTop(CPoint leftTop)
{
	m_leftTop = leftTop;
}

void CRectangle::SetWidth(double width)
{
	m_width = width;
}
void CRectangle::SetHeight(double height)
{
	m_height = height;
}