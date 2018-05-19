#pragma once
#include "stdafx.h"

std::shared_ptr<IShape> MakeFigure(std::string & figureInfo);
std::shared_ptr<IShape> FindFigureWithMaxArea(std::vector<std::shared_ptr<IShape>> & figures);
std::shared_ptr<IShape> FindFigureWithMinPerimeter(std::vector<std::shared_ptr<IShape>> & figures);