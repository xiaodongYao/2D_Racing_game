#include "Uti.h"

GLfloat Uti::aspect = 0.0f;


void Uti::glVertex2fAspect(int x, int y)
{
	if (Uti::aspect > 1.0)
	{
		glVertex2f(x * Uti::aspect, y);
	}
	else
	{
		glVertex2f(x, y / Uti::aspect);
	}
}

void Uti::renderBitmapString(float x, float y, void* font, const char* string) {
	if (Uti::aspect > 1.0)
	{
		glRasterPos2f(x * Uti::aspect, y);
	}
	else
	{
		glRasterPos2f(x, y / Uti::aspect);
	}

	for (const char* c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}