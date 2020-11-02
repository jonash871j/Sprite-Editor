#pragma once
#include "EngineCore.h"

class Draw
{
public:
	Draw();

	// Draw
	void Point(int x, int y, char character, byte color);

	void Background(char character, byte color);

	void Rectangle(int x1, int y1, int x2, int y2, char character, byte color, bool outline);

	void Line(int x1, int y1, int x2, int y2, char character, byte color);

	void Parabola(int x1, int y1, bool center, float a, float b, float c, float accuracy, char character, byte color);
};

