#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"
#include "CGFappearance.h"


class myTable: public CGFobject {
	private:
		float move;
		float angle;

		CGFappearance* materialLid;
		CGFappearance* materialLegs;

		CGFappearance* tableAppearance;
	public:
		myTable();
		void draw();
};

#endif