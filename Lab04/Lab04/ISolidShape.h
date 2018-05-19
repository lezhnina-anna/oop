#pragma once
#include <string>
#include "CShape.h"

class ISolidShape : virtual public IShape
{
public:
	virtual std::string GetFillColor() const = 0;
	virtual void SetFillColor(const std::string & color) = 0;
};
