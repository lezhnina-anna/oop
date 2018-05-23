#pragma once

#include "CSolidShape.h"
#include "CPoint.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, const std::string & fillColor, const std::string& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	void SetVertex1(CPoint vertex);
	void SetVertex2(CPoint vertex1);
	void SetVertex3(CPoint vertex1);
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_vertex1, m_vertex2, m_vertex3;
	double GetSideLen(const CPoint & v1, const CPoint & v2) const;
};
