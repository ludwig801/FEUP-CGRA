#include <GL/glut.h>
#include "Canvascamera.h"

Canvascamera::Canvascamera()
{
}

void Canvascamera::updateProjectionMatrix(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();

	// Sets an orthographic projection with x,y dimensions equal to the window size
	// and z limits containing the z=0 plane
	glOrtho(0,width,0,height, -0.1, 0.1);
}

void Canvascamera::applyView()
{
}

Canvascamera::~Canvascamera()
{
}
