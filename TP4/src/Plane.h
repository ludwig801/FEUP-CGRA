#pragma once

#include "CGF\CGFobject.h"
#include <iostream>
class Plane
{
public:
	Plane(void);
	Plane(int);
	Plane(int n, double si, double ti, double sf, double tf);

	~Plane(void);
	void draw();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	double si, sf;
	double ti, tf;

	double incS, incT;
};

