#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"

class myCylinder : public CGFobject {

	int slices;
	int stacks;
	bool smooth;
	
	int numVertex;

	double* vertX;
	double* vertY;

	public:
		myCylinder(int slices, int stacks, bool smooth);

		void draw();

};



#endif
