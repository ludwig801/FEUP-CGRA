#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "myUnitCube.h"
#include "myTable.h"
#include "myFloor.h"
#include "myChair.h"


class TPscene : public CGFscene
{
public:
	void init();
	void display();
};

#endif