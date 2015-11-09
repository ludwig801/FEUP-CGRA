#include "Plane.h"
#include <GL/GLU.h>


Plane::Plane(void)
{
	_numDivisions = 1;

	this->si = 0;
	this->ti = 0;
	this->sf = 1;
	this->tf = 1;

	this->incS = 1.0/_numDivisions;
	this->incT = 1.0/_numDivisions;

}

Plane::Plane(int n)
{
	_numDivisions = n;

	this->si = 0;
	this->ti = 0;
	this->sf = 1;
	this->tf = 1;

	this->incS = 1.0/_numDivisions;
	this->incT = 1.0/_numDivisions;

}

Plane::Plane(int n, double si, double ti, double sf, double tf)
{
	_numDivisions = n;

	this->si = si;
	this->ti = ti;
	this->sf = sf;
	this->tf = tf;

	this->incS = (fabs(si) + sf)/_numDivisions;
	this->incT = (fabs(ti) + tf)/_numDivisions;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		double coordS = si;
		double coordT = ti;

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2f(coordS,coordT);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{

					coordS += incS;
					glTexCoord2f(coordS,coordT);
					glVertex3f(bx + 1, 0, bz);

					coordS -= incS;
					coordT += incT;
					glTexCoord2f(coordS,coordT);
					glVertex3f(bx, 0, bz + 1);

				}

				coordS += incS;

				glTexCoord2f(coordS,coordT);
				glVertex3d(bx+ 1, 0, _numDivisions);

				coordT = ti;

			glEnd();
		}
	glPopMatrix();

}
