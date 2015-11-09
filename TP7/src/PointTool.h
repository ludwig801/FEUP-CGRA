#ifndef _POINTTOOL_H_
#define _POINTTOOL_H_

#include "CanvasTool.h"

class PointTool : public CanvasTool
{
public:
	PointTool(CGFcanvas *cnv):CanvasTool(cnv){};

	virtual void mousePressed(int x, int y);
	virtual void mouseReleased(int x, int y);
	virtual void mouseDragged(int x, int y);
};

#endif
