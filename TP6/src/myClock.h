#ifndef MYCLOCK_H
#define MYCLOCK_H

#include "CGFobject.h"
#include "myCylinder.h"
#include "myClockHand.h"
#include "CGFappearance.h"

class myClock: public CGFobject {
	private:

		int slices;

		myClockHand* clockSec;
		myClockHand* clockHour;
		myClockHand* clockMin;

		unsigned long clockTime;
		unsigned long lastTime;

		double secInc;
		double minInc;
		double hourInc;

	public:

		myClock(int slices);

		void draw();

		void update(unsigned long time);

		void setSec(myClockHand* sec);
		void setMin(myClockHand* min);
		void setHour(myClockHand* hour);

		void moveClockHands();

		void checkClock();
		void myClock::correctAngles();

		unsigned long getClockTime();

		void setLastTime(unsigned long time);
		unsigned long getLastTime();

		myClockHand* getSec();
		myClockHand* getMin();
		myClockHand* getHour();
};

#endif