#include "stdafx.h"
#include "CShape.h"

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

void CShape::SetOutlineColor(const std::string & color) 
{
	m_outlineColor = color;
}

std::string CShape::ToString() const
{
	std::ostringstream strm;
	strm << +"Outline Color: " << GetOutlineColor()  << std::endl;
	AppendProperties(strm);
	return strm.str();
}