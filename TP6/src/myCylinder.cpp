#include "myCylinder.h"
#include <math.h>

#include <iostream>

#define	PI	3.14159

myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;

	this->numVertex = slices;

	double angle = (2*PI)/slices;

	this->vertX = new double[slices];
	this->vertY = new double[slices];

	for(int i = 0; i < numVertex; i++) {
		vertX[i] = cos((angle/2.0) + i*angle);
		vertY[i] = sin((angle/2.0) + i*angle);
	}
}

void myCylinder::draw() {

	glPushMatrix();

	glTranslatef(0,-0.5,0);

	glBegin(GL_POLYGON);

	// Base
	for(int i = 0; i < numVertex; i++) {
		glNormal3f(0, -1, 0);
		glVertex3f(vertX[i],0,vertY[i]);
	}

	glEnd();


	// Faces
	double inc = 1.0/stacks;
	double angle = (2*PI)/this->slices;

	if(!smooth) {
		angle = -angle;
	}

	for(int i = 0; i < numVertex; i++) {

		for(int j = 0; j < stacks; j++) {


			glBegin(GL_POLYGON);

			if(!smooth) {
				glNormal3f(sin(i*angle), 0, cos(i*angle));
			}

			if(i == (numVertex - 1)) {
				if(smooth) {
					glNormal3f(vertX[i], 0, vertY[i]);
				}
				glVertex3f(vertX[i], j*inc, vertY[i]);
				glVertex3f(vertX[i], (j+1)*inc, vertY[i]);

				if(smooth) {
					glNormal3f(vertX[0], 0, vertY[0]);
				}
				glVertex3f(vertX[0], (j+1)*inc, vertY[0]);
				glVertex3f(vertX[0], j*inc, vertY[0]);
			} else {
				if(smooth) {
					glNormal3f(vertX[i], 0, vertY[i]);
				}
				glVertex3f(vertX[i], j*inc, vertY[i]);
				glVertex3f(vertX[i], (j+1)*inc, vertY[i]);
				if(smooth) {
					glNormal3f(vertX[i + 1], 0, vertY[i + 1]);
				}
				glVertex3f(vertX[i + 1], (j+1)*inc, vertY[i + 1]);
				glVertex3f(vertX[i + 1], j*inc, vertY[i + 1]);
			}

			glEnd();

		}

	}

	// Top
	glBegin(GL_POLYGON);

	double tg;

	glNormal3f(0, 1, 0);
	int j = 0;
	for(int i = numVertex - 1; i >= 0; i--) {
		glTexCoord2f((vertX[j] + 1)/2.0,(vertY[j] + 1)/2.0);
		glVertex3f(vertX[i],1,vertY[i]);
		j++;
	}

	glEnd();

	glPopMatrix();
}
