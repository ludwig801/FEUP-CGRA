#include "myChair.h"

myChair::myChair() {

	bool positive = rand() % 2;
	// Generates angle between 0 and 20
	angle = rand() % 21;

	if(!positive) angle = -angle;

	move = rand() % 1;

}

void myChair::draw() 
{
	myUnitCube leg1, leg2, leg3, leg4, lid, backboard;

	glTranslatef(move, 0, 0);
	glRotatef(angle, 0, 1, 0);


	glPushMatrix();
	glTranslatef(0.7, 1.1, 0.7);
	glScalef(0.3, 2.2, 0.3);
	leg1.draw();
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.7, 1.1, -0.7);
	glScalef(0.3, 2.2, 0.3);
	leg2.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.1, 1.1, 0.7);
	glScalef(0.3, 2.2, 0.3);
	leg3.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.1, 1.1, -0.7);
	glScalef(0.3, 2.2, 0.3);
	leg4.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.4, 2.35, 0);
	glScalef(1.7, 0.3, 1.7);
	lid.draw();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.4, 3.35, -0.7);
	glRotatef(90, 1, 0, 0);
	glScalef(1.7, 0.3, 2.3);
	backboard.draw();

	glPopMatrix();

}