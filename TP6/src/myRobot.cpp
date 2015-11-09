#include "myRobot.h"
#include <iostream>

#define	PI	3.14159

myRobot::myRobot() {

	this->faces = 4;

	// Robot's four faces
	for(int i = 0; i < faces; i++) {
		face[i] = new mySlice(4, 12, i);
	}

	// Initialize position and orientation
	this->orientation = 0; // in degrees
	this->posX = 7.5;
	this->posY = 0.2;
	this->posZ = 7.5;

	// Define default velocities for moving and rotating
	this->linearVelocity = 0.2;
	this->angularVelocity = 5.0; // in degrees
}

void myRobot::setLinearVelocity(double v) {
	this->linearVelocity = v;
}

void myRobot::setAngularVelocity(double v) {
	this->angularVelocity = v;
}

void myRobot::setOrientation(double o) {
	this->orientation = o;
}

void myRobot::turnLeft() {
	this->orientation -= this->angularVelocity;

	checkOrientation();
}

void myRobot::turnRight() {
	this->orientation += this->angularVelocity;
	
	checkOrientation();
}

void myRobot::moveForward() {
	this->posX += cos(PI*orientation/180.0)*this->linearVelocity;
	this->posZ -= sin(PI*orientation/180.0)*this->linearVelocity;
}

void myRobot::moveBackward() {
	this->posX -= cos(PI*orientation/180.0)*this->linearVelocity;
	this->posZ += sin(PI*orientation/180.0)*this->linearVelocity;
}

void myRobot::checkOrientation() {
	if(this->orientation >= 360)
		this->orientation -= 360;

	if(this->orientation < 0)
		this->orientation = 360;
}

void myRobot::draw() {

	double angle;
	
	for(int i = 0; i < faces; i++) {
		glPushMatrix();
			angle = i*90.0 + 45.0 + orientation;
			glRotated(angle,0,1,0);
			face[i]->draw();
		glPopMatrix();
	}

}