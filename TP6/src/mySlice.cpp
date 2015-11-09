#include "mySlice.h"
#include <iostream>

#define	PI	3.14159
#define CENTER	0.43

mySlice::mySlice(int stacks, int vertex, int face) {
	this->stacks = stacks;
	this->vertex = (vertex/4);

	this->face = face;

	this->inc = ((double)CENTER)/this->stacks;

	calculateVertex();
}

void mySlice::calculateVertex() {

	vector<double> norm, normTemp;
	vector<vector<double> > normStack, normStackTemp;

	double length;

	// Base
	for(int i = 0; i < (this->vertex + 1); i++) {
		vertBaseZ.push_back(0.5*(1 - ((double) i)/(vertex)));
		vertBaseX.push_back(-vertBaseZ[i] + 0.5);

		length = sqrt(2.0);

		norm.push_back(1.0/length);
		norm.push_back(1.0/length);

		normStack.push_back(norm);
		norm.clear();
	}

	vertN.push_back(normStack);
	normStack.clear();

	double angle = (PI/2.0)/vertex;

	// Top
	for(int i = 0; i < (this->vertex + 1); i++) {
		vertTopZ.push_back(0.25*cos(i*angle));
		vertTopX.push_back(0.25*sin(i*angle));

		length = sqrt((vertTopZ[i] * vertTopZ[i]) + (vertTopX[i] * vertTopX[i]));

		normTemp.push_back(vertTopX[i]/length);
		normTemp.push_back(vertTopZ[i]/length);

		normStackTemp.push_back(normTemp);
		normTemp.clear();
	}

	// *******************************************************************

	double increment;
	double x, y, z;

	double xNormal, zNormal;

	vector<double> vecX, vecY, vecZ;

	// Face:
	//   - Coordinates are calculated using a
	//	     linear interpolation between
	//       the top and the base.
	for(int i = 1; i < stacks; i++) {

		increment = ((double)i)/stacks;

		for(int j = 0; j <= this->vertex; j++) {

			z = vertBaseZ[j] - increment*(vertBaseZ[j] - vertTopZ[j]);
			x = vertBaseX[j] - increment*(vertBaseX[j] - vertTopX[j]);

			y = increment;

			vecX.push_back(x);
			vecY.push_back(y);
			vecZ.push_back(z);

			zNormal = increment + (1-increment)*vertTopZ[j];
			xNormal = increment + (1-increment)*vertTopX[j];
			
			length = sqrt((xNormal * xNormal) + (zNormal * zNormal));
	
			norm.push_back(xNormal/length);
			norm.push_back(zNormal/length);		

			normStack.push_back(norm);
			norm.clear();
		}

		vertX.push_back(vecX);
		vertY.push_back(vecY);
		vertZ.push_back(vecZ);

		vecX.clear();
		vecY.clear();
		vecZ.clear();

		vertN.push_back(normStack);
		normStack.clear();
	}

	vertN.push_back(normStackTemp);
	normStackTemp.clear();

	vector<double> temp0(vertX.size() + 2, 0.0);
	vector<double> temp1(vertX.size() + 2, 1.0);

	vertX.insert(vertX.begin(), vertBaseX);
	vertY.insert(vertY.begin(), temp0);
	vertZ.insert(vertZ.begin(), vertBaseZ);

	vertX.insert(vertX.end(), vertTopX);
	vertY.insert(vertY.end(), temp1);
	vertZ.insert(vertZ.end(), vertTopZ);

	// No more use for Base or Top vertex group (all vertex are now in vert -> X,Y,Z,N);
	vertBaseX.clear();
	vertBaseZ.clear();
	vertTopX.clear();
	vertTopZ.clear();
}

double mySlice::p(double s1, double s2) {
	return fabs((s2 - s1) / this->vertex);
}

void mySlice::drawSquareFace(int i, int j, double sI, double sF, double ssI, double ssF) {

	double vInc = 0;
	double vvInc = 0;

	double s0, s1, s2, s3;
	double t0, t1, t2, t3;

	s0 = 0;
	s1 = 0;
	s2 = 0;
	s3 = 0;

	t0 = 0;
	t1 = 0;
	t2 = 0;
	t3 = 0;

	switch(face) {
	case 0: // FRONT
		vInc = i * inc;
		vvInc = vInc + inc;

		s0 = sI + p(sI, sF)*(j);
		s1 = sI + p(sI, sF)*(j+1);
		s2 = ssI + p(ssI, ssF)*(j+1);
		s3 = ssI + p(ssI, ssF)*(j);

		t0 = vInc;
		t1 = vInc;
		t2 = vvInc;
		t3 = vvInc;
		break;
	case 1: // LEFT
		vInc = 1 - (i * inc);
		vvInc = vInc - inc;

		s0 = vInc;
		s1 = vInc;
		s2 = vvInc;
		s3 = vvInc;

		t0 = sI + p(sI, sF)*(j);
		t1 = sI + p(sI, sF)*(j+1);
		t2 = ssI + p(ssI, ssF)*(j+1);
		t3 = ssI + p(ssI, ssF)*(j);
		break;
	case 2: // BACK
		vInc = 1 - (i * inc);
		vvInc = vInc - inc;

		s0 = sI - p(sI, sF)*(j);
		s1 = sI - p(sI, sF)*(j+1);
		s2 = ssI - p(ssI, ssF)*(j+1);
		s3 = ssI - p(ssI, ssF)*(j);

		t0 = vInc;
		t1 = vInc;
		t2 = vvInc;
		t3 = vvInc;
		break;
	case 3: // RIGHT
		
		vInc = i * inc;
		vvInc = vInc + inc;

		s0 = vInc;
		s1 = vInc;
		s2 = vvInc;
		s3 = vvInc;

		t0 = sI - p(sI, sF)*(j);
		t1 = sI - p(sI, sF)*(j+1);
		t2 = ssI - p(ssI, ssF)*(j+1);
		t3 = ssI - p(ssI, ssF)*(j);
		break;
	default:
		return;
	}

	glBegin(GL_POLYGON);
		glNormal3f(vertN[i][j][0], 0, vertN[i][j][1]);
		glTexCoord2f(s0, t0);
		glVertex3f(vertX[i][j], vertY[i][j], vertZ[i][j]);

		glNormal3f(vertN[i][j+1][0], 0, vertN[i][j+1][1]);
		glTexCoord2f(s1, t1);
		glVertex3f(vertX[i][j+1], vertY[i][j+1], vertZ[i][j+1]);

		glNormal3f(vertN[i+1][j+1][0], 0, vertN[i+1][j+1][1]);
		glTexCoord2f(s2, t2);
		glVertex3f(vertX[i+1][j+1], vertY[i+1][j+1], vertZ[i+1][j+1]);

		glNormal3f(vertN[i+1][j][0], 0, vertN[i+1][j][1]);
		glTexCoord2f(s3, t3);
		glVertex3f(vertX[i+1][j], vertY[i+1][j], vertZ[i+1][j]);
	glEnd();
}

void mySlice::draw() {

	double s1, s2;
	double ss1, ss2;

	switch(face) {
	case 0: // FRONT
		s1 = 0.0;
		s2 = 1.0;
		ss1 = s1 + inc;
		ss2 = s2 - inc;
		break;
	case 1: // LEFT
		s1 = 0.0;
		s2 = 1.0;
		ss1 = s1 + inc;
		ss2 = s2 - inc;
		break;
	case 2: // RIGHT
		s1 = 1.0;
		s2 = 0.0;
		ss1 = s1 - inc;
		ss2 = s2 + inc;
		break;
	case 3: // BACK
		s1 = 1.0;
		s2 = 0.0;
		ss1 = s1 - inc;
		ss2 = s2 + inc;
		break;
	default:
		return;
	}

	// Draw faces
	for(int i = 0; i < this->stacks; i++) {
		for(int j = 0; j < this->vertex; j++) {

			drawSquareFace(i, j, s1, s2, ss1, ss2);
		}

		s1 = ss1;
		s2 = ss2;

		switch(face) {
		case 0: // FRONT
			ss1 += inc;
			ss2 -= inc;
			break;
		case 1: // LEFT
			ss1 += inc;
			ss2 -= inc;
			break;
		case 2: // RIGHT
			ss1 -= inc;
			ss2 += inc;
			break;
		case 3: // BACK
			ss1 -= inc;
			ss2 += inc;
			break;
		default:
			return;
		}

	}

	// Top can

	glNormal3f(0,1,0);
	int i = stacks;
	for(int j = 0; j < this->vertex; j++) {
		glBegin(GL_POLYGON);
		glTexCoord2f(CENTER, CENTER);	
		glVertex3f(vertX[i][j], 1, vertZ[i][j]);
		glVertex3f(vertX[i][j+1], 1, vertZ[i][j+1]);
		glVertex3f(0,1,0);
		glEnd();
	}

}