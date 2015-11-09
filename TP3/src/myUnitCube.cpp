#include "myUnitCube.h"

void myUnitCube::draw() 
{
	// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	// face parallel to XY (positive)
	glPushMatrix();
	glTranslatef(0,0,0.5);
	 glNormal3f(0,0,1);
	glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to XZ (positive)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0.5,0);
	glRotatef(-90,1,0,0);
	 glNormal3f(0,1,0);
	glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to XY (negative)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-0.5);
	glRotatef(180,0,1,0);
	 glNormal3f(0,0,-1);
	glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to XZ (negative)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-0.5,0);
	glRotatef(90,1,0,0);
	 glNormal3f(0,-1,0);
	glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to ZY (positive)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5,0,0);
	glRotatef(90,0,1,0);
	 glNormal3f(1,0,0);
	glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to ZY (negative)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5,0,0);
	glRotatef(-90,0,1,0);
	 glNormal3f(-1,0,0);
	glRectf(-0.5,-0.5,0.5,0.5);

	glPopMatrix();

	// ---- END Primitive drawing section
}