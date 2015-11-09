#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"

class myTable: public CGFobject {
	private:
		float move;
		float angle;
	public:
		myTable();
		void draw();
};

#endif