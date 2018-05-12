#pragma once

#include "CSolidShape.h"
#include "CPoint.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint center, double radius, const std::string & fillColor, const std::string& outlineColor);

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

	void SetCenter(CPoint center);
	void SetRadius(double radius);
private:
	CPoint m_center;
	double m_radius;
};