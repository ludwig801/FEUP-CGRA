#include <iostream>
#include "PointTool.h"

void PointTool::mousePressed(int x, int y)
{
	std::cout << "PointX: " << x << " PointY: " << y << std::endl;

	canvas->setPixel(x,y);
}

void PointTool::mouseDragged(int x, int y)
{
	canvas->setPixel(x,y);
}

void PointTool::mouseReleased(int x, int y)
{
}

