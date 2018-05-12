#pragma once
#include "IShape.h"

class CShape 
	: virtual public IShape
{
public:
	std::string GetOutlineColor() const override;
	void SetOutlineColor(const std::string & color);
private:
	std::string m_outlineColor;
};
