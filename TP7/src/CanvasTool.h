#ifndef _CANVASTOOL_H_
#define _CANVASTOOL_H_

#include "CGFcanvas.h"

class CanvasTool
{
public:
	CanvasTool(CGFcanvas *cnv){ canvas=cnv; };

	virtual void mousePressed(int x, int y)=0;
	virtual void mouseDragged(int x, int y)=0;
	virtual void mouseReleased(int x, int y)=0;

protected:
	CGFcanvas *canvas;
};

#endif