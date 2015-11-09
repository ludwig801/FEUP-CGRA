#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"
#include "myUnitCube.h"

// Random
#include <stdlib.h>
#include <time.h>

class myChair: public CGFobject {
	private:
		float angle;
		float move;
	public:
		myChair();
		void draw();
};

#endif