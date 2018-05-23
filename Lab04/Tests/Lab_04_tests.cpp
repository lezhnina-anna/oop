#include "stdafx.h"
#include "..\Lab04\CPoint.h"
#include "..\Lab04\CShape.h"
#include "..\Lab04\LineSegment.h"
#include "..\Lab04\CTriangle.h"
#include "..\Lab04\CRectangle.h"
#include "..\Lab04\CCircle.h"
#include "..\Lab04\ProcessFigures.h"
#include <sstream>

bool PointsAreEqual(const CPoint& first, const CPoint &second)
{
	return first == second;
}

// точка
BOOST_AUTO_TEST_SUITE(Point)

BOOST_AUTO_TEST_CASE(GetCoord)
{
	CPoint point(1, -1);
	
	BOOST_CHECK_EQUAL(point.x, 1);
	BOOST_CHECK_EQUAL(point.y, -1);
}

BOOST_AUTO_TEST_SUITE_END()

// линия
BOOST_AUTO_TEST_SUITE(LineSegment)

BOOST_AUTO_TEST_CASE(get_area_and_perimeter)
{
	CPoint start(0, 0);
	CPoint end(0, 2);
	std::string color = "red";
	CLineSegment line(start, end, color);
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 2);
}

BOOST_AUTO_TEST_CASE(to_string)
{
	CPoint start(0, 0);
	CPoint end(0, 2);
	std::string color = "red";

	CLineSegment line(start, end, color);
	std::ostringstream strm;

	strm << "Outline Color: " << line.GetOutlineColor() << "\n"
		<< "Shape Type : Line\n"
		<< "Start Point: " + line.GetStartPoint().ToString()
		<< "\nEnd Point is: " + line.GetEndPoint().ToString()
		<< "\nPerimeter: " + std::to_string(line.GetPerimeter())
		<< "\nArea: 0" << std::endl;

	BOOST_CHECK_EQUAL(strm.str(), line.ToString());
}

BOOST_AUTO_TEST_CASE(can_change_start_point_and_end_point)
{
	CPoint start(0, 0);
	CPoint end(0, 2);
	std::string color = "red";

	CLineSegment line(start, end, color);

	CPoint newEndPoint(0, -2);
	line.SetEndPoint(newEndPoint);

	BOOST_CHECK(PointsAreEqual(line.GetEndPoint(), newEndPoint));
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 2);
}
BOOST_AUTO_TEST_SUITE_END()

//круг
BOOST_AUTO_TEST_SUITE(Circle)

CPoint center(0, 0);
double radius = 2;

std::string fillColor = "red";
std::string outlineColor = "red";

CCircle circle(center, radius, fillColor, outlineColor);

BOOST_AUTO_TEST_CASE(make_new_correct_circle)
{
	BOOST_CHECK(PointsAreEqual(circle.GetCenter(), center));
	BOOST_CHECK_EQUAL(circle.GetRadius(), radius);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);

}

BOOST_AUTO_TEST_CASE(to_string)
{
	std::ostringstream strm;

	strm << "Outline Color: " << circle.GetOutlineColor()
		<< "\nFill Color: " << circle.GetFillColor() << "\n"
		<< "Shape Type : Circle\n"
		<< "Center: " + circle.GetCenter().ToString()
		<< "\nRadius: " + std::to_string(circle.GetRadius())
		<< "\nPerimeter: " + std::to_string(circle.GetPerimeter())
		<< "\nArea: " + std::to_string(circle.GetArea())
		<< std::endl;

	BOOST_CHECK_EQUAL(strm.str(), circle.ToString());
}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter)
{

	double area = 3.14159265*radius*radius;
	double perimeter = 3.14159265*radius * 2;

	BOOST_CHECK_EQUAL(circle.GetArea(), area);
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);
}

BOOST_AUTO_TEST_CASE(can_change_center_and_radius)
{
	CPoint newCenter(1, 1);
	double newRadius = 10;

	circle.SetCenter(newCenter);
	circle.SetRadius(newRadius);

	BOOST_CHECK(PointsAreEqual(circle.GetCenter(), newCenter));
	BOOST_CHECK_EQUAL(circle.GetRadius(), newRadius);
}

BOOST_AUTO_TEST_SUITE_END()

//треугольник
BOOST_AUTO_TEST_SUITE(Triangle)


CPoint v1(0, 3);
CPoint v2(4, 0);
CPoint v3(0, 0);


std::string fillColor = "red";
std::string outlineColor = "white";

CTriangle triangle(v1, v2, v3, fillColor, outlineColor);

BOOST_AUTO_TEST_CASE(make_new_correct_triangle)
{
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex1(), v1));
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex2(), v2));
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex3(), v3));
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), outlineColor);

}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter)
{
	BOOST_CHECK_EQUAL(triangle.GetArea(), 6);
	BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 12);
}

BOOST_AUTO_TEST_CASE(can_change_vertex)
{
	CPoint newV1(1, 1), newV2(0, 2), newV3(0, 0);

	triangle.SetVertex1(newV1);
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex1(), newV1));

	triangle.SetVertex2(newV2);
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex2(), newV2));

	triangle.SetVertex3(newV3);
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex3(), newV3));
}

BOOST_AUTO_TEST_CASE(to_string)
{
	std::ostringstream strm;

	strm << "Outline Color: " << triangle.GetOutlineColor()
		<< "\nFill Color: " << triangle.GetFillColor() << "\n"
		<< "Shape Type : Triangle\n"
		<< "First Vertex: " + triangle.GetVertex1().ToString()
	    << "\nSecond Vertex: " + triangle.GetVertex2().ToString()
		<< "\nThird Vertex: " + triangle.GetVertex3().ToString()
		<< "\nPerimeter: " + std::to_string(triangle.GetPerimeter())
		<< "\nArea: " + std::to_string(triangle.GetArea())
	    << std::endl;

	BOOST_CHECK_EQUAL(strm.str(), triangle.ToString());
}

BOOST_AUTO_TEST_SUITE_END()

//прямоугольник
BOOST_AUTO_TEST_SUITE(Rectangle)

CPoint point(1, 1);
double width = 10;
double height = 5;
std::string fillColor = "red";
std::string outlineColor = "red";

CRectangle rec(point, width, height, fillColor, outlineColor);

BOOST_AUTO_TEST_CASE(make_new_correct_rectangle)
{
	BOOST_CHECK(PointsAreEqual(rec.GetLeftTop(), point));
	BOOST_CHECK_EQUAL(rec.GetHeight(), 5);
	BOOST_CHECK_EQUAL(rec.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rec.GetOutlineColor(), outlineColor);
	BOOST_CHECK_EQUAL(rec.GetFillColor(), fillColor);
}

BOOST_AUTO_TEST_CASE(to_string)
{
	std::ostringstream strm;

	strm << "Outline Color: " << rec.GetOutlineColor()
		<< "\nFill Color: " << rec.GetFillColor() << "\n"
		<< "Shape Type : Rectangle\n"
		<<"Left Top Vertex: " + rec.GetLeftTop().ToString()
		<< "\nRight Bottom Vertex: " + rec.GetRightBottom().ToString()
		<< "\nWidth: " + std::to_string(rec.GetWidth())
		<< "\nHeight: " + std::to_string(rec.GetHeight())
		<< "\nPerimeter: " + std::to_string(rec.GetPerimeter())
		<< "\nArea: " + std::to_string(rec.GetArea())
		<< std::endl;

	BOOST_CHECK_EQUAL(strm.str(), rec.ToString());
}

BOOST_AUTO_TEST_CASE(get_right_bottom)
{
	BOOST_CHECK(PointsAreEqual(rec.GetRightBottom(), CPoint(11, -4)));
}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter)
{

	double area = width*height;
	double perimeter = 2*(width+height);

	BOOST_CHECK_EQUAL(rec.GetArea(), area);
	BOOST_CHECK_EQUAL(rec.GetPerimeter(), perimeter);
}

BOOST_AUTO_TEST_CASE(can_change_width_and_height)
{
	double newWidth = 1;
	double newHeight = 10;
	rec.SetWidth(newWidth);
	rec.SetHeight(newHeight);
	BOOST_CHECK_EQUAL(rec.GetWidth(), newWidth);
	BOOST_CHECK_EQUAL(rec.GetHeight(), newHeight);
} 

BOOST_AUTO_TEST_CASE(can_change_left_top)
{
	CPoint point(3, 2);
	rec.SetLeftTop(point);
	BOOST_CHECK(PointsAreEqual(rec.GetLeftTop(), point));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Find_figure_with_max_area_and_min_perimeter)

std::vector<std::shared_ptr<IShape>> figures;
std::string circleInfo = "circle 2 2 1 red white";
std::string rectangleInfo = "rectangle 2 2 5 10 red white";

BOOST_AUTO_TEST_CASE(max_area)
{
	figures.push_back(MakeFigure(circleInfo));
	figures.push_back(MakeFigure(rectangleInfo));
	double maxArea = FindFigureWithMaxArea(figures)->GetArea();
	BOOST_CHECK_EQUAL(maxArea, 50);
}

BOOST_AUTO_TEST_CASE(min_perimeter)
{
	const double PI = 3.14159265;
	double radius = 1;
	figures.push_back(MakeFigure(circleInfo));
	figures.push_back(MakeFigure(rectangleInfo));
	double minPerimeter = FindFigureWithMinPerimeter(figures)->GetPerimeter();
	BOOST_CHECK_EQUAL(minPerimeter, 2* PI *radius);
}
BOOST_AUTO_TEST_SUITE_END()

