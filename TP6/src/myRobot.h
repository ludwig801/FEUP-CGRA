#ifndef MYROBOT_H
#define MYROBOT_H

#include "CGFobject.h"
#include "CGFappearance.h"
#include "mySlice.h"

class myRobot: public CGFobject {
private:

	int stacks;
	int faces;

	double posX, posY, posZ;
	double orientation;

	double linearVelocity;
	double angularVelocity;

	mySlice *face[4];

public:
	myRobot();

	void draw();

	void setLinearVelocity(double v);
	void setAngularVelocity(double v);
	void setOrientation(double o);

	double getOrientation() { return orientation; }
	double getLinearVelocity() { return linearVelocity; }
	double getAngularVelocity() { return angularVelocity; }
	double getX() { return posX; }
	double getY() { return posY; }
	double getZ() { return posZ; }

	void turnLeft();
	void turnRight();
	void moveForward();
	void moveBackward();
	void checkOrientation();
};

#endif