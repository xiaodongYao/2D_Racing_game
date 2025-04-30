#pragma once

#include "GL/freeglut.h"

//For Display TEXT ×ÖÌå
//void* font1 = GLUT_BITMAP_TIMES_ROMAN_24;
//void* font2 = GLUT_BITMAP_HELVETICA_18;
//void* font3 = GLUT_BITMAP_8_BY_13;

class Uti
{
public:
    static void glVertex2fAspect(int x, int y);
    static void renderBitmapString(float x, float y, void* font, const char* string);
    static GLfloat aspect;
};


