#include "RectTool.h"

void RectTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	fx=x;
	fy=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawRect(sx,sy,fx,fy);
}

void RectTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawRect(sx,sy,fx,fy);

	// Update current coordinates
	fx=x;
	fy=y;

	// Draw new line
	drawRect(sx,sy,fx,fy);
}

void RectTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawRect(sx,sy,fx,fy);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawRect(sx,sy,x,y);
}



void RectTool::drawRect(int xi, int yi, int xf, int yf)
{

	checkCoord(xi, xf, yi, yf);


	drawHorizontalLine(xi, xf, yi);
	drawHorizontalLine(xi, xf, yf);

	drawVerticalLine(yi, yf, xi);
	drawVerticalLine(yi, yf, xf);

}


void RectTool::drawHorizontalLine(const int xi, const int xf, const int y) {

	for (int x = xi; xf > x; x++) {
		canvas->setPixel(x, y);
	}

}

void RectTool::drawVerticalLine(const int yi, const int yf, const int x) {

	for (int y = yi; yf > y; y++) {
		canvas->setPixel(x, y);
	}

}

void RectTool::checkCoord(int & xi, int & xf, int & yi, int & yf) {

	if(xf < xi) {
		swap(xi, xf);
	}

	if(yf < yi) {
		swap(yi, yf);
	}

}

void RectTool::swap(int & val1, int & val2) {

	int tmp = val2;
	val2 = val1;
	val1 = tmp;

}