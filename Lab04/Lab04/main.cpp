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
			//std::cout << figure->ToString() << "\n";
		}
		else
		{
			std::cout << "Error: Undefined Figure" << std::endl;
		}	
	}

	std::cout << "Figure with max area:\n" << FindFigureWithMaxArea(figures)->ToString() << "\n";
	std::cout << "Figure with min perimeter:\n" << FindFigureWithMinPerimeter(figures)->ToString() << "\n";


	/*
	
	std::cout << point.x << " " << point.y;

	CLineSegment line(point, point, "red");
	std::cout << line.ToString() << "\n";

	CRectangle newR(point, 10, 10, "red", "green");
	std::cout << newR.ToString() << "\n";


	CCircle newC(point, 20, "blue", "white");
	std::cout << newC.ToString() << "\n";*/
	CPoint point1(5, 0);
	CPoint point2(3, 10);


	CPoint point(1, 0);
	CTriangle newT(point, point1, point2, "black", "pink");
	std::cout << newT.ToString() << "\n";

    return 0;
}
