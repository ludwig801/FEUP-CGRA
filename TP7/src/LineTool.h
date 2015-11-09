#ifndef _LINETOOL_H_
#define _LINETOOL_H_

#include "CanvasTool.h"

class LineTool : public CanvasTool
{
public:
	LineTool(CGFcanvas *cnv):CanvasTool(cnv){};

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawLine(int xi, int yi, int xf, int yf);

	void checkCoord(int & xi, int & xf, int & yi, int & yf);
	void checkOctant(int & xi, int & xf, int & yi, int & yf);

	void drawInFirstQuadrant(int xi, int xf, int yi, int yf);

	void swap(int & val1, int & val2);

	int sx, sy, currx, curry, direction, quadrant, octant;
};

#endif
