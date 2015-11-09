#ifndef _CANVASSCENE_H
#define _CANVASSCENE_H

#include "CGFscene.h"
#include "CGFcanvas.h"

class CanvasScene : public CGFscene
{
public:
	CanvasScene();
	void init();
	void display();

	~CanvasScene();

	CGFcanvas *canvas;

};

#endif