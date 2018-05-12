#pragma once
#include "stdafx.h"

std::shared_ptr<IShape> MakeFigure(std::string & figureInfo);
void AddFigureToVector(std::shared_ptr<IShape> & figure, std::vector<std::shared_ptr<IShape>> & figures);