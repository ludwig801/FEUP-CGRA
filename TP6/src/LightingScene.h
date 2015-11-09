#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myClock.h"
#include "myClockHand.h"
#include "myRobot.h"
#include "mySlice.h"
#include "myWindowWall.h"

#include <vector>

using namespace std;

class LightingScene : public CGFscene
{
public:
	int sceneVar;
	bool clockUpdate;
	bool robotTextured;

	int robotTex;

	void init();
	void display();
	void update(unsigned long time);

	// Lights
	void toggleLights(int light, int value);
	
	// Clock
	void toggleClock(int value);
	void resetClock();
	void setClock(int hour, int min, int sec);
	void changeClockUpdateStatus();

	// Robot
	void changeRobotTexture(int texID);
	void changeRobotTextureMode();
	void changeRobotLinearVelocity(double value);
	void changeRobotAngularVelocity(double value);
	void rotateRobot(int direction);
	void moveRobot(int direction);

	myRobot* getRobot();
	myClock* getClock();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	CGFlight* lightWindow;

	myTable* table;
	Plane* wall;
	Plane* leftWall;
	Plane* boardA;
	Plane* boardB;
	Plane* floor;

	Plane* landscape;

	WindowWall* windowWall;

	myClock* clock;

	myCylinder* column;
	myCylinder* column2;

	myRobot* robot;

	// TEMP
	mySlice* slice;

	CGFappearance* material;

	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* wallAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;

	CGFappearance* landscapeAppearance;

	CGFappearance* clockAppearance;
	CGFappearance* clockSecColor;
	CGFappearance* clockMinColor;
	CGFappearance* clockHourColor;

	vector<CGFappearance*> robotAppearance;

	~LightingScene();
};

#endif