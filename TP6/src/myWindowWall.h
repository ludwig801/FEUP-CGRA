#ifndef MYWWALL_H
#define MYWWALL_H

#include "CGF\CGFobject.h"
#include "Plane.h"


#include <iostream>

class WindowWall {
	public:
		WindowWall(void);

		~WindowWall(void);

		void draw();

	private:

		Plane* division[4];
		int numberOfDivisions;

		int _numDivisions; // Number of triangles that constitute rows/columns

		double si, sf;
		double ti, tf;

		double incS, incT;
};

#endif