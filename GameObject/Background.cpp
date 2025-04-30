#include "Background.h"
#include "../Utility/Uti.h"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

//Init BackGround
void BackGround::drawBackGround()
{
	//Road Background
	glColor3f(0.000, 0.392, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(0, 55);
	Uti::glVertex2fAspect(100, 55);
	glColor3f(0.604, 0.804, 0.196);
	Uti::glVertex2fAspect(100, 0);
	Uti::glVertex2fAspect(0, 0);
	glEnd();


	//Road Sky
	glColor3f(0.000, 0.749, 1.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(0, 100);
	Uti::glVertex2fAspect(100, 100);
	glColor3f(0.686, 0.933, 0.933);
	Uti::glVertex2fAspect(100, 55);
	Uti::glVertex2fAspect(0, 55);
	glEnd();
}

//Init Road
void BackGround::drawRoadInit()
{
    //Road Design In Front Page
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    Uti::glVertex2fAspect(51, 55);
    Uti::glVertex2fAspect(90, 0);
    Uti::glVertex2fAspect(10, 0);
    glEnd();

    //Road Midle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    Uti::glVertex2fAspect(51, 55);
    Uti::glVertex2fAspect(52, 0);
    Uti::glVertex2fAspect(48, 0);
    glEnd();
}

//Hill nearHill==true 近处的山
void hill(int x1, int  y1, int x2, int  y2, int x3, int  y3, bool nearHill)
{
    if (nearHill)
    {
        glColor3f(0.000, 0.502, 0.000);
    }
    else
    {
        glColor3f(0.235, 0.702, 0.443);
    }
    glBegin(GL_TRIANGLES);
    Uti::glVertex2fAspect(x1 + 20, y1 + 65);
    Uti::glVertex2fAspect(x2 + 27, y2 + 55);
    Uti::glVertex2fAspect(x3 + 0, y3 + 55);
    glEnd();

}

void BackGround::drawHill()
{
    //far hill 
    hill(0, 0, 0, 0, 0, 0, false); //20-65 ,27-55 ,0-55
    hill(67, 0, 73, 0, 60, 0, false);

    //near hill
    hill(15, 2, 24, 0, 10, 0, true);
    hill(50, 5, 63, 0, 51, 0, true);
}



void tree(int x, int y)
{
    //Tree Left
    //Bottom
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    Uti::glVertex2fAspect(x + 11, y + 55);
    Uti::glVertex2fAspect(x + 12, y + 45);
    Uti::glVertex2fAspect(x + 10, y + 45);
    glEnd();

    //Up
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    Uti::glVertex2fAspect(x + 11, y + 58);
    Uti::glVertex2fAspect(x + 15, y + 52);
    Uti::glVertex2fAspect(x + 7, y + 52);
    glEnd();
}

void BackGround::drawTree()
{
    tree(0, 0);
    tree(5, -15);
    tree(9, 5);
    tree(85, 9);
    tree(75, -5);
}


void BackGround::drawRoadStart()
{
    //Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(20, 0);
    Uti::glVertex2fAspect(20, 100);
    Uti::glVertex2fAspect(80, 100);
    Uti::glVertex2fAspect(80, 0);
    glEnd();


    //Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(20, 0);
    Uti::glVertex2fAspect(20, 100);
    Uti::glVertex2fAspect(23, 100);
    Uti::glVertex2fAspect(23, 0);
    glEnd();

    //Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(77, 0);
    Uti::glVertex2fAspect(77, 100);
    Uti::glVertex2fAspect(80, 100);
    Uti::glVertex2fAspect(80, 0);
    glEnd();
}


void BackGround::drawRoadDynamic(unsigned int roadDivTop, unsigned int roadDivMdl, unsigned int roadDivBtm)
{
    //Road Middel Border
    //TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(48, roadDivTop + 80);
    Uti::glVertex2fAspect(48, roadDivTop + 100);
    Uti::glVertex2fAspect(52, roadDivTop + 100);
    Uti::glVertex2fAspect(52, roadDivTop + 80);
    glEnd();

    //Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(48, roadDivMdl + 40);
    Uti::glVertex2fAspect(48, roadDivMdl + 60);
    Uti::glVertex2fAspect(52, roadDivMdl + 60);
    Uti::glVertex2fAspect(52, roadDivMdl + 40);
    glEnd();

    //Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    Uti::glVertex2fAspect(48, roadDivBtm + 0);
    Uti::glVertex2fAspect(48, roadDivBtm + 20);
    Uti::glVertex2fAspect(52, roadDivBtm + 20);
    Uti::glVertex2fAspect(52, roadDivBtm + 0);
    glEnd();
}


