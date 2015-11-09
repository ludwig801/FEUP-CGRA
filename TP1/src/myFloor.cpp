#include "myFloor.h"

void myFloor::draw() {

	// Bottom face
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRectf(0, 0, 8, 6);

	// Top face
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0.1, 6);
	glRotatef(-90, 1, 0, 0);
	glRectf(0, 0, 8, 6);

	// XY face
	glPopMatrix();
	glPushMatrix();
	glRectf(0, 0, 8, 0.1);

	// Positive parallel to XY face
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 6);
	glRectf(0, 0, 8, 0.1);

	// ZY face
	glPopMatrix();
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glRectf(0, 0, 6, 0.1);

	// Positive parallel to ZY face
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8, 0, 6);
	glRotatef(90, 0, 1, 0);
	glRectf(0, 0, 6, 0.1);


	glPopMatrix();
}
