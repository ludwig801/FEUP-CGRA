#include "LineTool.h"

void LineTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;
	direction = 0;
	quadrant = 1;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawLine(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx,sy,x,y);
}

//void LineTool::drawLine(int xi, int yi, int xf, int yf)
//{
//	// draws a line; 
//	// simple flawed version, only draws in quadrants 1 and 4, 
//	// and iterates over x, meaning there will be gaps on octants 2 and 7
//	// where abs(delta y) > abs(delta x)
//
//	float m;
//	if (xf!=xi)
//		m=(float) (yf-yi)/(float)(xf-xi);
//	else
//		m=0;
//
//	for (int x=xi;x<=xf;x++)
//		canvas->setPixel(x,yi+(x-xi)*m);
//}


void LineTool::drawLine(int xi, int yi, int xf, int yf) {

	//checkCoord(xi, xf, yi, yf);

	switch(quadrant) {
	case 1:
		drawInFirstQuadrant(xi, xf, yi, yf);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}


}

void LineTool::checkCoord(int & xi, int & xf, int & yi, int & yf) {

	if(xi > xf) {

		swap(xi, xf);

		if(yi > yf) { // 3rd octanct.
			swap(yi, yf);
			direction = 0;
		} else { // 2nd octant.
			direction = 1; 
		}

	} else {

		if(yi > yf) { // 4th octanct
			swap(yi, yf);
			direction = 1;
		} else {
			direction = 0;
		}

	} 

}

void LineTool::checkOctant(int & xi, int & xf, int & yi, int & yf) {

	if((xf - xi) < (yf - yi)) {
		direction = 1;
	} else {
		direction = 0;
	}
}

void LineTool::swap(int & val1, int & val2) {

	int tmp = val2;
	val2 = val1;
	val1 = tmp;

}

void LineTool::drawInFirstQuadrant(int xi, int xf, int yi, int yf) {

	int dx = xf - xi;
	int dy = yf - yi;

	checkOctant(xi, xf, yi, yf);

	if(!direction) {

		int d = 2*dy - dx;
		int d1 = 2*(dy - dx);
		int d2 = 2*dy;

		int y = yi;

		for(int x = xi; x <= xf; x++) {

			canvas->setPixel(x, y);	

			if(d <= 0) {
				d += d2;
			} else {
				d += d1;
				y++;
			}
			
		}

	} else {

		int d = 2*dx - dy;
		int d1 = 2*(dx - dy);
		int d2 = 2*dx;

		int x = xi;

		for(int y = yi; y <= yf; y++) {

			canvas->setPixel(x, y);	

			if(d <= 0) {
				d += d2;
			} else {
				d += d1;
				x++;
			}

		}

	}

}