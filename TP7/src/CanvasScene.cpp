#include "CanvasScene.h"
#include "CGFapplication.h"
#include "Canvascamera.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

CanvasScene::CanvasScene() 
{
	// intialize base scene
	CGFscene();

	// replace base scene camera by a canvas camera 
	// (orthographic, pixel-accurate units)
	activeCamera =  new Canvascamera();
}

void CanvasScene::init() 
{
	// Disables lighting computations
	glDisable(GL_LIGHTING);

	// Creates a new canvas of 512 x 512 pixels
	canvas=new CGFcanvas(512,512);
}

void CanvasScene::display() 
{

	// ---- BEGIN Background and camera setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	activeCamera->applyView();

	// draw/update canvas rendering on screen
	// this in practice draws a textured quad 
	// scaled in such a way that each texel will correspond to a pixel
	canvas->draw();

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

CanvasScene::~CanvasScene() 
{
	// free the camera
	delete(activeCamera);

	// free the canvas
	delete(canvas);

}