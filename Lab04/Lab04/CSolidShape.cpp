#include "stdafx.h"
#include "CSolidShape.h"

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetFillColor(const std::string & color)
{
	m_fillColor = color;
}

std::string CSolidShape::ToString() const
{
	std::ostringstream strm;
	strm <<  "Outline Color: " + GetOutlineColor()
		+ "\nFill Color: " + GetFillColor() << "\n";
	AppendProperties(strm);
	return strm.str();
}