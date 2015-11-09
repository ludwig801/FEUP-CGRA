#include "myTable.h"

myTable::myTable() {

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
	lid.draw();

	glPopMatrix();
}