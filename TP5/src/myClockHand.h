#ifndef MYCLOCKHAND_H
#define MYCLOCKHAND_H

#include "CGFobject.h"
#include "CGFappearance.h"

class myClockHand: public CGFobject {
	private:

		double angle;
	public:

		myClockHand();

		void draw();

		void setAngle(double angle);

		void add(double angle);

		void incrementAngle();

		double getAngle();
};

#endif