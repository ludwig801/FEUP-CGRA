#include "myUnitCube.h"

void myUnitCube::draw() 
{
	// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	// face parallel to XY (positive)
	glPushMatrix();
	 glNormal3f(0,0,1);

	glBegin(GL_POLYGON);
		glTexCoord2f(1,1);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,0.5);
	glEnd();

	//glRectf(-0.5,-0.5,0.5,0.5);

	// face parallel to XZ (positive)
	glPopMatrix();
	glPushMatrix();
	 glNormal3f(0,1,0);

	glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	// face parallel to XY (negative)
	glPopMatrix();
	glPushMatrix();
	 glNormal3f(0,0,-1);

	glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
		glVertex3f(0.5,-0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,0.5,-0.5);
	glEnd();

	// face parallel to XZ (negative)
	glPopMatrix();
	glPushMatrix();
	 glNormal3f(0,-1,0);

	glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
		glVertex3f(0.5,-0.5,-0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	// face parallel to ZY (positive)
	glPopMatrix();
	glPushMatrix();
	 glNormal3f(1,0,0);

	glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
		glVertex3f(0.5,-0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,-0.5);
		glTexCoord2f(1,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
	glEnd();

	// face parallel to ZY (negative)
	glPopMatrix();
	glPushMatrix();
	 glNormal3f(-1,0,0);

	glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	glPopMatrix();

	// ---- END Primitive drawing section
}