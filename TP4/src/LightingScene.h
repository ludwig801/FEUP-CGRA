#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	CGFlight* lightWindow;

	myTable* table;
	Plane* wall;
	Plane* windowWall;
	Plane* boardA;
	Plane* boardB;
	Plane* floor;

	myCylinder* column;
	myCylinder* column2;

	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* wallAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;

	~LightingScene();
};

#endif