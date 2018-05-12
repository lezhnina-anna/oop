// Lab04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProcessFigures.h"

int main()
{
	std::string info = "Figures info\n";
	info += "line: <line><start point><end point><color>\n"
		"rectangle: <rectangle><left top><width><height><fill color><outline color>\n"
		"triangle: <triangle><vertex1><vertex2><vertex3><fill color><outline color>\n"
		"circle: <circle><center><radius><fill color><outline color>\n"
		"point: <x><y>";

	std::cout << info << std::endl;

	std::vector<std::shared_ptr<IShape>> figures;
	std::string figureInfo;

	while (getline(std::cin, figureInfo))
	{
		std::shared_ptr<IShape> figure = MakeFigure(figureInfo);
		if (figure)
		{
			figures.push_back(figure);
			std::cout << figure->ToString();
		}
		else
		{
			std::cout << "Error: Undefined Figure" << std::endl;
		}
		//copy(figures.begin(), figures.end(), std::ostream_iterator<IShape>(std::cout, " "));
	}
	
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
	std::cout << newC.ToString() << "\n";*/

    return 0;
}
