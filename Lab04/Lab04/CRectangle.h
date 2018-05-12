#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, const std::string & fillColor, const std::string& outlineColor);

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;
	
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	void SetLeftTop(CPoint leftTop);
	void SetWidth(double width);
	void SetHeight(double height);

private:
	CPoint m_leftTop;
	double m_width, m_height;
};
