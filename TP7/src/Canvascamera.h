#ifndef CG_Canvascamera
#define CG_Canvascamera

#include "CGFcamera.h"

/**
 * @file Canvascamera.h
 * Camera class for the CGF framework.
 * 
 * This class can be used to implement a point of view for the application.
 */

class Canvascamera: public CGFcamera {
	public:
		Canvascamera();
		~Canvascamera();

		void applyView();
		void updateProjectionMatrix(int width, int height);
};

#endif
