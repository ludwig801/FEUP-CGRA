#include "myTable.h"

// Coefficients for table material
float ambLid[3] = {0.1, 0.1, 0.1};
float difLid[3] = {0.2, 0.07, 0.04};
float specLid[3] = {0.1, 0.1, 0.1};
float shininessLid = 0.f;

// Coefficients for table material
float ambLegs[3] = {0.3, 0.3, 0.3};
float difLegs[3] = {0.5, 0.5, 0.5};
float specLegs[3] = {0.8, 0.8, 0.8};
float shininessLegs = 100.f;

myTable::myTable() {

	materialLid = new CGFappearance(ambLid,difLid,specLid,shininessLid);
	materialLegs = new CGFappearance(ambLegs,difLegs,specLegs,shininessLegs);

	bool positive = rand() % 2;
	// Generates angle between 0 and 20
	angle = rand() % 8;

	if(!positive) angle = -angle;

	move = rand() % 1;

}

void myTable::draw() 
{
	myUnitCube leg1, leg2, leg3, leg4, lid;

	glTranslatef(move, 0, 0);
	glRotatef(angle, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-2.2,-1.9,-1.2);
	glScalef(0.3,3.5,0.3);

	materialLegs->apply();
	leg1.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.2,-1.9,-1.2);
	glScalef(0.3,3.5,0.3);
	leg2.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.2,-1.9,1.2);
	glScalef(0.3,3.5,0.3);
	leg3.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.2,-1.9,1.2);
	glScalef(0.3,3.5,0.3);
	leg4.draw();

	glPopMatrix();
	glPushMatrix();
	glScalef(5,0.3,3);

	materialLid->apply();
	lid.draw();

	glPopMatrix();
}