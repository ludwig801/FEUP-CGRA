#ifndef MYSCLICE_H
#define MYSCLICE_H

#include "CGFobject.h"
#include "CGFappearance.h"

#include <vector>

class mySlice: public CGFobject {
private:
	int stacks;
	int vertex;

	int face;

	double inc;

	vector<double> vertBaseX;
	vector<double> vertBaseZ;

	vector<double> vertTopX;
	vector<double> vertTopZ;

	vector<vector<double> > vertX;
	vector<vector<double> > vertY;
	vector<vector<double> > vertZ;

	vector<vector<vector<double> > > vertN;

public:
	mySlice(int stacks, int vertex, int face);

	void calculateVertex();

	double p(double s1, double s2);

	void drawSquareFace(int i, int j, double s1, double s2, double ss1, double ss2);

	void draw();
};

#endif