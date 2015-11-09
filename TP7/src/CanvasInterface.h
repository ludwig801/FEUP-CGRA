#ifndef CanvasInterface_H
#define CanvasInterface_H

#include "CGFinterface.h"
#include "CanvasTool.h"

// Adjust below for adding more tools
#define TOOL_SIZE 3

class CanvasInterface: public CGFinterface {

	public:

		virtual void initGUI();
		virtual void processGUI(GLUI_Control *ctrl);

		virtual void processMouse(int button, int state, int x, int y);
		virtual void processMouseMoved(int x, int y);

	private:

		void convertCoords(int *x, int *y);

		CanvasTool *tools[TOOL_SIZE];
		int activeToolID;
};


#endif
