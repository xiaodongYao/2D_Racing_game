#include "car.h"
#include "GL/freeglut.h"
#include "../Utility/Uti.h"

CarObject::CarObject(unsigned int lrIndex, unsigned int  offset, float r, float g, float b) :lrIndex(lrIndex), offset(offset), R(r), G(g), B(b)
{
}

CarObject::~CarObject()
{
}

void CarObject::reset(unsigned int lrIndex, unsigned int  offset)
{
	this->offset = offset;
	this->lrIndex = lrIndex;
}

void CarObject::draw() const
{
	glColor3f(0.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 24, offset + 96);
	Uti::glVertex2fAspect(lrIndex + 24, offset + 94);
	Uti::glVertex2fAspect(lrIndex + 32, offset + 94);
	Uti::glVertex2fAspect(lrIndex + 32, offset + 96);
	glEnd();
	glColor3f(0.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 24, offset + 100);
	Uti::glVertex2fAspect(lrIndex + 24, offset + 98);
	Uti::glVertex2fAspect(lrIndex + 32, offset + 98);
	Uti::glVertex2fAspect(lrIndex + 32, offset + 100);
	glEnd();
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 26, offset + 100);
	Uti::glVertex2fAspect(lrIndex + 26, offset + 93);
	Uti::glVertex2fAspect(lrIndex + 28, offset + 91);
	Uti::glVertex2fAspect(lrIndex + 30, offset + 93);
	Uti::glVertex2fAspect(lrIndex + 30, offset + 100);
	glEnd();
}

void CarObject::drawPlayer() const
{
	glColor3f(0.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 24, 5);
	Uti::glVertex2fAspect(lrIndex + 24, 7);
	Uti::glVertex2fAspect(lrIndex + 32, 7);
	Uti::glVertex2fAspect(lrIndex + 32, 5);
	glEnd();

	//Back Tire
	glColor3f(0.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 24, 1);
	Uti::glVertex2fAspect(lrIndex + 24, 3);
	Uti::glVertex2fAspect(lrIndex + 32, 3);
	Uti::glVertex2fAspect(lrIndex + 32, 1);
	glEnd();

	//Car body
	glColor3f(0.678, 1.000, 0.184);
	glBegin(GL_POLYGON);
	Uti::glVertex2fAspect(lrIndex + 26, 1);
	Uti::glVertex2fAspect(lrIndex + 26, 8);
	glColor3f(0.000, 0.545, 0.545);

	Uti::glVertex2fAspect(lrIndex + 28, 10);
	Uti::glVertex2fAspect(lrIndex + 30, 8);
	Uti::glVertex2fAspect(lrIndex + 30, 1);
	glEnd();
}