#include "myClockHand.h"

myClockHand::myClockHand() {

	this->angle = 0;

}

void myClockHand::draw() 
{
	
	//// back face
	//glBegin(GL_POLYGON);
	//	glNormal3f(0,0,-1);
	//	glVertex3f(-0.1,0,-0.1);
	//	glVertex3f(0,1,0);
	//	glVertex3f(0.1,0,-0.1);
	//glEnd();

	//// bottom face
	//glBegin(GL_POLYGON);
	//	glNormal3f(0,-1,0);
	//	glVertex3f(-0.1,0,0.1);
	//	glVertex3f(-0.1,0,-0.1);
	//	glVertex3f(0.1,0,-0.1);
	//	glVertex3f(0.1,0,0.1);
	//glEnd();

	//// right face
	//glBegin(GL_POLYGON);
	//	glNormal3f(1,0.1,0);
	//	glVertex3f(0.1,0,-0.1);
	//	glVertex3f(0,1,0);
	//	glVertex3f(0.1,0,0.1);
	//glEnd();

	//// left face
	//glBegin(GL_POLYGON);
	//	glNormal3f(-1,0.1,0);
	//	glVertex3f(-0.1,0,0.1);
	//	glVertex3f(0,1,0);
	//	glVertex3f(-0.1,0,-0.1);
	//glEnd();

	// front face
	glBegin(GL_POLYGON);
		glNormal3f(0,0,1);
		glVertex3f(0.1,0,0);
		glVertex3f(0,1,0);
		glVertex3f(-0.1,0,0);
	glEnd();

	glPopMatrix();
}

void myClockHand::setAngle(double angle) {
	this->angle = angle;
}

void myClockHand::incrementAngle() {
	if(angle == 359) angle = 0;
	else angle++;
}

double myClockHand::getAngle() {
	return this->angle;
}

void myClockHand::add(double angle) {
	this->angle += angle;
}

