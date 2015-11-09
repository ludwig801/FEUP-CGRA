#include "TPinterface.h"
#include "LightingScene.h"

#define	LEFT	0
#define RIGHT	1
#define FORWARD	1
#define BACK	0

TPinterface::TPinterface()
{
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
		case 'j': // Rotate Robot Left
		{
			((LightingScene *) scene)->rotateRobot(LEFT);
			break;
		}

		case 'l': // Rotate Robot Right
		{
			((LightingScene *) scene)->rotateRobot(RIGHT);
			break;
		}

		case 'i': // Move Robot Forward
		{
			((LightingScene *) scene)->moveRobot(FORWARD);
			break;
		}

		case 'k': // Move Robot Backwards
		{
			((LightingScene *) scene)->moveRobot(BACK);
			break;
		}
	}
}

void TPinterface::initGUI()
{
	light0 = 1;
	light1 = 1;
	light2 = 1;

	clock = 1;

	//hour = ((LightingScene *) scene)->getClock()->getHour()->;

	texture = 0;
	mode = 0;

	linearV = ((LightingScene *) scene)->getRobot()->getLinearVelocity();
	angularV = ((LightingScene *) scene)->getRobot()->getAngularVelocity();


	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *lightsPanel= addPanel("Lights", 1);
	addColumn();

	addCheckboxToPanel(lightsPanel,"Board 1 light", &light0, 1);
	addCheckboxToPanel(lightsPanel,"Board 2 light", &light1, 2);
	addCheckboxToPanel(lightsPanel,"Window light", &light2, 3);

	GLUI_Panel *clockPanel= addPanel("Clock", 1);
	addColumn();
	addButtonToPanel(clockPanel, "Pause", 4);
	addButtonToPanel(clockPanel, "Reset", 5);

	GLUI_Panel *robotPanel= addPanel("Robot", 1);
	GLUI_Listbox *textureList = addListboxToPanel(robotPanel, "Texture", &texture, 6);
	textureList->add_item(0, "Default");
	textureList->add_item(1, "Military");

	GLUI_RadioGroup *textureMode = addRadioGroupToPanel(robotPanel, &mode, 7);
	addRadioButtonToGroup(textureMode, "Textured");
	addRadioButtonToGroup(textureMode, "Wireframe");

	addColumnToPanel(robotPanel);

	addEditTextToPanel(robotPanel, "Linear Velocity", &linearV, 8);
	addEditTextToPanel(robotPanel, "Angular Velocity", &angularV, 9);
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("\nGUI control id: %d\n  ", ctrl->user_id);

	switch (ctrl->user_id)
	{
		case 1:
		{
			((LightingScene *) scene)->toggleLights(0, light0);
			break;
		};

		case 2:
		{
			((LightingScene *) scene)->toggleLights(1, light1);
			break;
		};

		case 3:
		{
			((LightingScene *) scene)->toggleLights(2, light2);
			break;
		};

		case 4:
		{
			((LightingScene *) scene)->toggleClock(0);
			clock = !clock;

			if(clock) {
				ctrl->name = "Pause";
			}
			else {
				ctrl->name = "Resume";
			}
			break;
		};

		case 5:
		{
			((LightingScene *) scene)->toggleClock(1);
			break;
		};

		case 6:
		{
			((LightingScene *) scene)->changeRobotTexture(texture);
			break;
		};

		case 7:
		{
			((LightingScene *) scene)->changeRobotTextureMode();
			break;
		};

		case 8:
		{
			((LightingScene *) scene)->changeRobotLinearVelocity((double)linearV);
			break;
		};

		case 9:
		{
			((LightingScene *) scene)->changeRobotAngularVelocity((double)angularV);
			break;
		};
	};

	syncVars();
}

