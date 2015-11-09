#ifndef _RECTTOOL_H
#define _RECTTOOL_H

#include "CanvasTool.h"

class RectTool : public CanvasTool
{
public:
	RectTool(CGFcanvas *cnv):CanvasTool(cnv){};

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawRect(int xi, int yi, int xf, int yf);

	void drawHorizontalLine(const int xi, const int xf, const int y);
	void drawVerticalLine(const int yi, const int yf, const int x);

	void checkCoord(int & xi, int & xf, int & yi, int & yf);
	void swap(int & val1, int & val2);

	int sx, sy, fx, fy;
};

#endif
