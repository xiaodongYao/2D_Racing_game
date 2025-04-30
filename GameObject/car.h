#pragma once


class CarObject
{
public:
	CarObject(unsigned int lrIndex, unsigned int  offset, float r, float g, float b);
	~CarObject();

	int  lrIndex;
	int  offset;
	float R;
	float G;
	float B;
	void reset(unsigned int lrIndex, unsigned int  offset);
	void draw() const;

	void drawPlayer() const;
};