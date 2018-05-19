#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, const std::string & fillColor, const std::string& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	void SetLeftTop(CPoint leftTop);
	void SetWidth(double width);
	void SetHeight(double height);
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_leftTop;
	double m_width, m_height;
};
