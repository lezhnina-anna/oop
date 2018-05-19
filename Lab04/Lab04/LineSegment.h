#pragma once

#include "CShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint& first, CPoint &second, const std::string& color);

	double GetArea()const override;
	double GetPerimeter()const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	void SetStartPoint(CPoint startPoint);
	void SetEndPoint(CPoint endPoint);
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
