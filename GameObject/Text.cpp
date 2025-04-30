#include <iostream>
#include "Text.h"
#include "../Utility/Uti.h"

//For Display TEXT ×ÖÌå
void* font1 = GLUT_BITMAP_TIMES_ROMAN_24;
void* font2 = GLUT_BITMAP_HELVETICA_18;
void* font3 = GLUT_BITMAP_8_BY_13;



Text::Text() {

}

Text::~Text()
{

}

void Text::RenderTextInit()
{
	//Menu Place Holder
	glColor3f(00, 0, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(32 - 4, 50 + 5 + 10);
	Uti::glVertex2fAspect(32 + 46, 50 + 5 + 10);
	Uti::glVertex2fAspect(32 + 46, 50 - 15 + 10);
	Uti::glVertex2fAspect(32 - 4, 50 - 15 + 10);
	glEnd();

	glColor3f(0.098, 0.098, 0.439);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(32 - 3, 50 + 4 + 10);
	Uti::glVertex2fAspect(32 + 45, 50 + 4 + 10);
	Uti::glVertex2fAspect(32 + 45, 50 - 14 + 10);
	Uti::glVertex2fAspect(32 - 3, 50 - 14 + 10);
	glEnd();

	glColor3f(1.000, 1.000, 0.000);
	Uti::renderBitmapString(31, 80, font1, "2D Car Racing Game ");

	glColor3f(0.000, 1.000, 0.000);
	Uti::renderBitmapString(31, 60, font2, "Press SPACE to START");
	Uti::renderBitmapString(31, 57, font2, "Press ESC to Exit");

	glColor3f(1.000, 1.000, 1.000);
	Uti::renderBitmapString(31, 50 - 6 + 10, font3, "Press UP to increase Speed");
	Uti::renderBitmapString(31, 50 - 8 + 10, font3, "Press DWON to decrease Speed");
	Uti::renderBitmapString(31, 50 - 10 + 10, font3, "Press RIGHT to turn Right");
	Uti::renderBitmapString(31, 50 - 12 + 10, font3, "Press LEFT to turn Left");

	glColor3f(0.000, 1.000, 1.000);
	Uti::renderBitmapString(31 - 5, 50 - 40, font3, "Project By:");
	Uti::renderBitmapString(31 - 5, 50 - 43, font3, "yao");
}

void Text::RenderTextEnd(unsigned int score)
{
	glColor3f(1.000, 0.000, 0.000);
	Uti::renderBitmapString(35, 60 + 10, font1, "GAME OVER");
	char buffer2[50];
	sprintf(buffer2, "Your Score is : %d", score);
	Uti::renderBitmapString(35, 60 - 4 + 10, font1, buffer2);
}

void Text::RenderTextStart(unsigned int score, unsigned int FPS, unsigned int level)
{
	//Score Board
	glColor3f(0.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(80, 97);
	Uti::glVertex2fAspect(100, 97);
	Uti::glVertex2fAspect(100, 90);
	Uti::glVertex2fAspect(80, 90);
	glEnd();

	//Print Score
	char buffer[50];
	sprintf(buffer, "SCORE: %d", score);
	glColor3f(0.000, 1.000, 0.000);
	Uti::renderBitmapString(80.5, 95, font3, buffer);

	//Speed Print
	char buffer1[50];
	sprintf(buffer1, "SPEED:%dKm/h", FPS);
	glColor3f(0.000, 1.000, 0.000);
	Uti::renderBitmapString(80.5, 93, font3, buffer1);

	//print level
	char level_buffer[50];
	sprintf(level_buffer, "LEVEL: %d", level);
	glColor3f(0.000, 1.000, 0.000);
	Uti::renderBitmapString(80.5, 91, font3, level_buffer);
}
