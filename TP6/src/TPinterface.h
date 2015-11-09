#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"

class TPinterface: public CGFinterface {
	public:
		TPinterface();

		virtual void initGUI();
		virtual void processGUI(GLUI_Control *ctrl);

		virtual void processKeyboard(unsigned char key, int x, int y);

		int light0, light1, light2;
		int clock;
		int texture, mode;


		float linearV, angularV;
};


#endif
