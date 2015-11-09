#ifndef _CGFCCANVAS_H_
#define _CGFCCANVAS_H_

#include <GL/glut.h>

#define CANVAS_PIXEL_TYPE unsigned char
#define CANVAS_INVALID_COLOR -1

class CGFcanvas
{
public:
	CGFcanvas(int width, int height);
	~CGFcanvas(void);

	void clear();
	void setPixel(int x, int y);
	CANVAS_PIXEL_TYPE getPixel(int x, int y);
	void setColor(CANVAS_PIXEL_TYPE color);

	void setNormalMode();
	void setXORMode();

	void draw();

private:

	void markAllChanged();
	void markChangedPixel(int x, int y);
	void resetChangedArea();
	void updateChangedAreaToTexture();

	CANVAS_PIXEL_TYPE *data;
	int w,h;
	GLuint texName;

	int minChangedLine, maxChangedLine;

	CANVAS_PIXEL_TYPE currentColor;
	CANVAS_PIXEL_TYPE currentBackgroundColor;

	unsigned char currentMode;
};

#endif
