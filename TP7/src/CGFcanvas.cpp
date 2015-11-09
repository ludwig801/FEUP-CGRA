#include <stdlib.h>
#include <memory.h>

#include "CGFcanvas.h"

#define CANVAS_CLEAR_COLOR 255
#define CANVAS_DEFAULT_COLOR 0
#define CANVAS_PIXEL_SIZE sizeof(CANVAS_PIXEL_TYPE)

#define CANVAS_NORMAL_MODE 0
#define CANVAS_XOR_MODE 1

CGFcanvas::CGFcanvas(int width, int height)
{
	// Store dimensions
	w=width;
	h=height;

	// Allocates memory for holding the image data
	data=(CANVAS_PIXEL_TYPE*) malloc(w*h*CANVAS_PIXEL_SIZE);

	// Sets up OpenGL texture with single-byte alignment
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Creates and binds a texture
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	// Sets up basic texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	// set up initial colors and mode
	currentColor=CANVAS_DEFAULT_COLOR;
	currentBackgroundColor=CANVAS_CLEAR_COLOR;
	setNormalMode();

	// clear the buffer to the background color
	clear();

	// Load initial data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, w, h, 
                0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);

	// mark the whole area as unchanged, since the data is up to date now
	resetChangedArea();

}

void CGFcanvas::clear(void)
{
	// fills the image with the background color
	memset(data,currentBackgroundColor,w*h*CANVAS_PIXEL_SIZE); 	//NOTE: for pixel formats other than BYTE, memset may be a bad option
	// Marks the whole image as changed
	markAllChanged();
}

void CGFcanvas::markAllChanged()
{
	// sets the first and last lines as the boundaries for the changed region
	minChangedLine=0;
	maxChangedLine=h-1;
}


void CGFcanvas::markChangedPixel(int x, int y)
{
	// extends the upper or lower boundaries of the changed area 
	// to include the provided pixel
	if (y>maxChangedLine)
		maxChangedLine=y;

	if (y<minChangedLine)
		minChangedLine=y;
}

void CGFcanvas::resetChangedArea()
{
	// resets the changed area i.e., marks min > max so that it signals nothing is changed
	minChangedLine=h;
	maxChangedLine=0;
}

CANVAS_PIXEL_TYPE CGFcanvas::getPixel(int x, int y)
{
	// returns the color at the requested coordinates, if valid
	if ( x>= 0 && x<w && y>=0 && y <h)
	{
		return data[x+y*w];
	}
	else 
		return CANVAS_INVALID_COLOR;
}

void CGFcanvas::setColor(CANVAS_PIXEL_TYPE color)
{
	currentColor=color;
}

void CGFcanvas::setNormalMode()
{
	currentMode=CANVAS_NORMAL_MODE;
}

void CGFcanvas::setXORMode()
{
	currentMode=CANVAS_XOR_MODE;
}

void CGFcanvas::setPixel(int x, int y)
{
	// sets the color at the requested coordinates, if valid
	// in XOR mode, performs a bitwise XOR between the color of the pixel in the image and the current (active) color
	if ( x>= 0 && x<w && y>=0 && y <h)
	{
		if (currentMode==CANVAS_NORMAL_MODE)
			data[x+y*w]=currentColor;
		else 
			data[x+y*w]=data[x+y*w] ^ currentColor;

		// marks the pixel as changed
		markChangedPixel(x,y);
	}
}


void CGFcanvas::updateChangedAreaToTexture()
{
	// only updates if there was some change
	if (minChangedLine<=maxChangedLine)
	{
		// binds the texture
		glBindTexture(GL_TEXTURE_2D, texName);

		// updates all the lines of the area marked as changed
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, minChangedLine, w,
							 maxChangedLine-minChangedLine+1, GL_LUMINANCE,
							 GL_UNSIGNED_BYTE, data+minChangedLine*w);
		// marks all unchanged
		resetChangedArea();
	}
}

void CGFcanvas::draw(void)
{
	// sets up texturing
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName);

	// updates texture data (if needed)
	updateChangedAreaToTexture();

	// draws scaled quad
	glPushMatrix();
	glScalef(w,h,1);
	glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex2f(0,0);

		glTexCoord2f(1,0);
		glVertex2f(1,0);

		glTexCoord2f(1,1);
		glVertex2f(1,1);

		glTexCoord2f(0,1);
		glVertex2f(0,1);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

CGFcanvas::~CGFcanvas(void)
{
	// frees the texture in OpenGL
	glDeleteTextures(1,&texName);

	// frees the texture data
	free(data);
}
