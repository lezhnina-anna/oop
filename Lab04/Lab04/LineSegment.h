#pragma once

#include "CShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint& first, CPoint &second, const std::string& color);

	virtual double GetArea()const override;
	virtual double GetPerimeter()const override;
	virtual std::string ToString()const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	void SetStartPoint(CPoint startPoint);
	void SetEndPoint(CPoint endPoint);
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
