#include "stdafx.h"
#include "..\Lab04\CPoint.h"
#include "..\Lab04\CShape.h"
#include "..\Lab04\LineSegment.h"
#include "..\Lab04\CTriangle.h"
#include "..\Lab04\CRectangle.h"
#include "..\Lab04\CCircle.h"
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
	/*
	BOOST_CHECK_EQUAL(point.GetX(), 1);
	BOOST_CHECK_EQUAL(point.GetY(), -1);*/
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
//	circle.GetOutlineColor();

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

CPoint v1(0, 0);
CPoint v2(1, 0);
CPoint v3(0, 1);


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
/*
BOOST_AUTO_TEST_CASE(get_area_and_perimeter)
{

	double area = 3.14159265*radius*radius;
	double perimeter = 3.14159265*radius * 2;

	BOOST_CHECK_EQUAL(triangle.GetArea(), area);
	BOOST_CHECK_EQUAL(triangle.GetPerimeter(), perimeter);
}*/

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

BOOST_AUTO_TEST_SUITE_END()

/*
CPoint point(1, 0);
std::cout << point.x << " " << point.y;

CLineSegment line(point, point, "red");
std::cout << line.ToString() << "\n";

CRectangle newR(point, 10, 10, "red", "green");
std::cout << newR.ToString() << "\n";

CPoint point1(5, 0);
CPoint point2(3, 10);

CTriangle newT(point, point1, point2, "black", "pink");
std::cout << newT.ToString() << "\n";

CCircle newC(point, 20, "blue", "white");
std::cout << newC.ToString() << "\n"; 

*/