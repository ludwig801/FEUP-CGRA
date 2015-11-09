#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

float lightWindow_pos[4] = {1.0, 4, 7.5, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {1.0,1.0,1.0,2.0};

// number of divisions
#define BOARD_A_DIVISIONS 4
#define BOARD_B_DIVISIONS 100
#define WINDOW_DIVISIONS 40
#define FLOOR_DIVISIONS 40

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
//float specA[3] = {0.2, 0.2, 0.2};
float specA[3] = {0.0, 0.8, 0.8};
//float shininessA = 10.f;
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for floor texture
float ambFloor[3] = {0.2, 0.2, 0.2};
float difFloor[3] = {0.38, 0.46, 0.59};
float specFloor[3] = {0.2, 0.2, 0.2};
float shininessFloor = 5.f;

// Coefficients for wall texture
float ambWall[3] = {0.2, 0.2, 0.2};
float difWall[3] = {0.89, 0.86, 0.82};
float specWall[3] = {0.2, 0.2, 0.2};
float shininessWall = 1.f;

// Coefficients for window texture
float ambWindow[3] = {0.2, 0.2, 0.2};
float difWindow[3] = {0.89, 0.86, 0.82};
float specWindow[3] = {0.2, 0.2, 0.2};
float shininessWindow = 1.f;

// Coefficients for slides texture
float ambSlides[3] = {0.2, 0.2, 0.2};
float difSlides[3] = {0.8, 0.8, 0.8};
float specSlides[3] = {0.2, 0.2, 0.2};
float shininessSlides = 0.f;

// Coefficients for board texture
float ambBoard[3] = {0.2, 0.2, 0.2};
float difBoard[3] = {0.3, 0.3, 0.3};
float specBoard[3] = {0.7, 0.7, 0.7};
float shininessBoard = 5.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};
float white[4]={1,1,1,1};

int GL_CLAMP_TO_EDGE = 0x812f;

void LightingScene::init() 
{

	// Enable flat Shading
	//glShadeModel(GL_FLAT);

	// Enable smooth Shading
	glShadeModel(GL_SMOOTH);

	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	// glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
	
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	//light0->disable();
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	//light1->disable();
	light1->enable();

	/* Window Light */
	lightWindow = new CGFlight(GL_LIGHT2, lightWindow_pos);
	lightWindow->setAmbient(ambientNull);
	lightWindow->setSpecular(white);
	//lightWindow->setKc(0.0);
	//lightWindow->setKl(0.0);
	//lightWindow->setKq(1.0);

	//lightWindow->disable();
	lightWindow->enable();

	// Uncomment below to enable normalization of lighting normal vectors
	glEnable(GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();

	windowWall = new Plane(WINDOW_DIVISIONS, -1.375, -0.5, 2.375, 1.5);

	floor = new Plane(FLOOR_DIVISIONS, 0, 0, 10, 12);

	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS, 0, 0, 1, 1.37);

	column = new myCylinder(8,2,false);
	column2 = new myCylinder(8,2,true);

	slidesAppearance = new CGFappearance("textures/slides.png",GL_REPEAT,GL_REPEAT);
	slidesAppearance->setAmbient(ambSlides);
	slidesAppearance->setDiffuse(difSlides);
	slidesAppearance->setSpecular(specSlides);
	slidesAppearance->setShininess(shininessSlides);

	boardAppearance = new CGFappearance();
	boardAppearance->setTexture(new CGFtexture("textures/board.png"));
	boardAppearance->setTextureWrap(GL_CLAMP_TO_EDGE,GL_CLAMP_TO_EDGE);
	boardAppearance->setAmbient(ambBoard);
	boardAppearance->setDiffuse(difBoard);
	boardAppearance->setSpecular(specBoard);
	boardAppearance->setShininess(shininessBoard);

	wallAppearance = new CGFappearance();
	wallAppearance->setTexture(new CGFtexture("textures/wall.png"));
	wallAppearance->setTextureWrap(GL_REPEAT,GL_REPEAT);
	wallAppearance->setAmbient(ambWall);
	wallAppearance->setDiffuse(difWall);
	wallAppearance->setSpecular(specWall);
	wallAppearance->setShininess(shininessWall);

	windowAppearance = new CGFappearance();
	windowAppearance->setTexture(new CGFtexture("textures/window.png"));
	windowAppearance->setTextureWrap(GL_CLAMP_TO_EDGE,GL_CLAMP_TO_EDGE);
	windowAppearance->setAmbient(ambWindow);
	windowAppearance->setDiffuse(difWindow);
	windowAppearance->setSpecular(specWindow);
	windowAppearance->setShininess(shininessWindow);

	floorAppearance = new CGFappearance();
	floorAppearance->setTexture(new CGFtexture("textures/floor.png"));
	floorAppearance->setTextureWrap(GL_REPEAT,GL_REPEAT);
	floorAppearance->setAmbient(ambFloor);
	floorAppearance->setDiffuse(difFloor);
	floorAppearance->setSpecular(specFloor);
	floorAppearance->setShininess(shininessFloor);
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
		glTranslated(5,3.65,8);

		//tableAppearance->setTextureWrap(1,1);
		//tableAppearance->apply();
		table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,3.65,8);

		table->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);

		floorAppearance->apply();
		floor->draw();
	glPopMatrix();

	//LeftWall (with window)
	glPushMatrix();
		glTranslated(0,4,7.5);
		
		glRotated(90.0,1,0,0);
		glRotated(-90.0,0,0,1);
		glScaled(15,0.2,8);
		
		windowAppearance->apply();
		windowWall->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);

		wallAppearance->apply();
		wall->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);

		slidesAppearance->apply();
		boardA->draw();
	glPopMatrix();
	
	// Board B
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);

		boardAppearance->apply();
		boardB->draw();
	glPopMatrix();

	//// Column
	//glPushMatrix();
	//	glTranslated(4,4,4);
	//	glScaled(1, 8, 1);
	//	column->draw();
	//glPopMatrix();

	//// Column2
	//glPushMatrix();
	//	glTranslated(12,4,4);
	//	glScaled(1, 8, 1);
	//	column2->draw();
	//glPopMatrix();
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);

	delete(floor);
	delete(windowWall);
	delete(column);
	delete(column2);
}