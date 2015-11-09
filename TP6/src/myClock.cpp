#include "myClock.h"

#include <iostream>

// Coefficients for clock material
float ambClock[3] = {0.1, 0.1, 0.1};
float difClock[3] = {0.8, 0.8, 0.8};
float specClock[3] = {0.05, 0.05, 0.05};
float shininessClock = 0.f;

#define SECOND	1000

myClock::myClock(int slices) {

	this->clockTime = 0;
	this->lastTime = 0;

	this->secInc = 360.0/60.0;
	this->minInc = 360.0/(3600.0);
	this->hourInc = 360.0/(43200.0);

	this->slices = slices;

}

void myClock::draw() 
{

	myCylinder clock = myCylinder(this->slices, 1, true);

	clock.draw();

	glPopMatrix();
}

void myClock::setSec(myClockHand* sec) {
	this->clockSec = sec;
}

void myClock::setMin(myClockHand* min) {
	this->clockMin = min;
}

void myClock::setHour(myClockHand* hour) {
	this->clockHour = hour;
}

myClockHand* myClock::getSec() {
	return this->clockSec;
}

myClockHand* myClock::getMin() {
	return this->clockMin;
}

myClockHand* myClock::getHour() {
	return this->clockHour;
}

unsigned long myClock::getClockTime() {
	return this->clockTime;
}

void myClock::setLastTime(unsigned long time) {
	this->lastTime = time;
}

unsigned long myClock::getLastTime() {
	return this->lastTime;
}

void myClock::moveClockHands() {
	this->clockSec->add(secInc);
	this->clockMin->add(minInc);
	this->clockHour->add(hourInc);
}

void myClock::checkClock() {
	if(this->clockSec->getAngle() >= 360) {
		this->clockSec->setAngle(0);
	}
	if(this->clockMin->getAngle() >= 360) {
		this->clockMin->setAngle(0);
	}
	if(this->clockHour->getAngle() >= 360) {
		this->clockHour->setAngle(0);
	}
}

void myClock::correctAngles() {
	double secondsPassed = this->clockSec->getAngle()*60.0/360.0;
	this->clockMin->add(secondsPassed*this->minInc);

	secondsPassed += this->clockMin->getAngle()*10;
	this->clockHour->add(secondsPassed*this->hourInc);
}

void myClock::update(unsigned long time) {

	if(this->lastTime == 0) {
		this->lastTime = time;
	}
	else {
		unsigned long passedTime = (time - this->lastTime); // Seconds

		this->lastTime = time;
		this->clockTime += passedTime;

		if((this->clockTime / SECOND) > 0) {

			this->clockTime -= SECOND;

			this->moveClockHands();

			this->checkClock();
		}
	}
}
