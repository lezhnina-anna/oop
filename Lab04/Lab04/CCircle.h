#pragma once

#include "CSolidShape.h"
#include "CPoint.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint center, double radius, const std::string & fillColor, const std::string& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

	void SetCenter(CPoint center);
	void SetRadius(double radius);
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_center;
	double m_radius;
};