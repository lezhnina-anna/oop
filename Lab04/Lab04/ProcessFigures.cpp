#include "stdafx.h"
#include "ProcessFigures.h"

std::shared_ptr<IShape> ReadLine(std::istream& in)
{
	double x, y;

	in >> x >> y;
	CPoint startPoint(x, y);

	in >> x >> y;
	CPoint endPoint(x, y);

	std::string color;
	in >> color;

	return std::make_shared<CLineSegment>(startPoint, endPoint, "red");
}

std::shared_ptr<IShape> ReadRectangle(std::istream& in)
{
	double x, y, height, width;
	in >> x >> y >> height >> width;
	CPoint leftTop(x, y);

	std::string fillColor, outlineColor;
	in >> fillColor >> outlineColor;

	return std::make_shared<CRectangle>(leftTop, width, height, fillColor, outlineColor);
}

std::shared_ptr<IShape> ReadCircle(std::istream& in)
{
	double x, y, radius;
	in >> x >> y >> radius;
	CPoint center(x, y);

	std::string fillColor, outlineColor;
	in >> fillColor >> outlineColor;

	return std::make_shared<CCircle>(center, radius, fillColor, outlineColor);
}

std::shared_ptr<IShape> ReadTriangle(std::istream& in)
{
	double x, y;

	in >> x >> y;
	CPoint vertex1(x, y);

	in >> x >> y;
	CPoint vertex2(x, y);

	in >> x >> y;
	CPoint vertex3(x, y);

	std::string fillColor, outlineColor;
	in >> fillColor >> outlineColor;

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, fillColor, outlineColor);
}

std::shared_ptr<IShape> MakeFigure(std::string & figureInfo)
{
	std::stringstream in{ figureInfo };
	std::string figureType;
	in >> figureType;

	if (figureType == "line")
	{
		return ReadLine(in);
	}
	else if (figureType == "circle")
	{
		return ReadCircle(in);
	}
	else if (figureType == "rectangle")
	{
		return ReadRectangle(in);
	}
	else if (figureType == "triangle")
	{
		return ReadTriangle(in);
	}

	return nullptr;

}


std::shared_ptr<IShape> FindFigureWithMaxArea(std::vector<std::shared_ptr<IShape>> & figures)
{
	if (figures.empty())
	{
		return nullptr;
	}

	return *max_element(figures.begin(), figures.end(), [](auto& left, auto& right) -> bool {
		return left->GetArea() < right->GetArea();
	});
}

std::shared_ptr<IShape> FindFigureWithMinPerimeter( std::vector<std::shared_ptr<IShape>> & figures)
{
	if (figures.empty())
	{
		return nullptr;
	}

	return *min_element(figures.begin(), figures.end(), [](auto& left, auto& right) -> bool {
		return left->GetPerimeter() < right->GetPerimeter();
	});
}
