#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myClock.h"
#include "myClockHand.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long time);

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

	myClock* clock;
	//myClockHand* clockSec;
	//myClockHand* clockMin;
	//myClockHand* clockHour;

	myCylinder* column;
	myCylinder* column2;

	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* wallAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;

	CGFappearance* clockAppearance;
	CGFappearance* clockSecColor;
	CGFappearance* clockMinColor;
	CGFappearance* clockHourColor;

	~LightingScene();
};

#endif