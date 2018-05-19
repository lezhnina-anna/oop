#pragma once
#include "ISolidShape.h"

class CSolidShape : public CShape, public ISolidShape
{
public:
	std::string GetFillColor() const override;
	void SetFillColor(const std::string & color) override;
	std::string ToString() const override;
protected:
	void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_fillColor;
};

