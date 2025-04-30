#pragma once

#include "GL/freeglut_std.h"

class BackGround 
{
public:
	BackGround();
	~BackGround();

	//Init;
	void drawBackGround();
	void drawRoadInit();
    void drawHill();
	void drawTree();

	//Start:
	void drawRoadStart();
    void drawRoadDynamic(unsigned int roadDivTop, unsigned int roadDivMdl, unsigned int roadDivBtm);

	//End:


};