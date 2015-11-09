#include "myWindowWall.h"

#define WINDOW_DIVISIONS 40

WindowWall::WindowWall() {
	division[0] = new Plane(WINDOW_DIVISIONS, -31/32.0, -0.5,  1/32.0, 1.50);
	division[1] = new Plane(WINDOW_DIVISIONS, 0.0, 28/32.0, 1.0, 53/32.0);
	division[2] = new Plane(WINDOW_DIVISIONS, 0.0, -31/32.0, 1.0, 1/32.0);
	division[3] = new Plane(WINDOW_DIVISIONS, 31/32.0, -0.5, 53/32.0, 1.50);

	numberOfDivisions = 4;
}

void WindowWall::draw() {

	glPushMatrix();

	// Left division
	///glTranslated(5,1,5);
	glTranslated(0,4,12.5);
	glScaled(1,8,5);
	glRotated(90.0,1,0,0);
	glRotated(-90.0,0,0,1);
	division[0]->draw();

	// Upper division
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,7,7.5);
	glScaled(1,2,5);
	glRotated(90.0,0,1,0);
	glRotated(90.0,1,0,0);
	division[1]->draw();

	// Lower division
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,1,7.5);
	glScaled(1,2,5);
	glRotated(90.0,0,1,0);
	glRotated(90.0,1,0,0);
	division[2]->draw();

	// Right division
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,4,2.5);
	glScaled(1,8,5);
	glRotated(90.0,1,0,0);
	glRotated(-90.0,0,0,1);
	division[3]->draw();

	glPopMatrix();
}

WindowWall::~WindowWall() {
	for(int i = 0; i < numberOfDivisions; i++)
		delete(division[i]);
}