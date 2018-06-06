#pragma once
#include "IShape.h"

class CShape 
	: virtual public IShape
{
public:
	std::string GetOutlineColor() const override;
	void SetOutlineColor(const std::string & color);
	std::string ToString() const final;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_outlineColor;
};
