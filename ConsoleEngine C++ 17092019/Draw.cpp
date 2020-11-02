#include "Draw.h"
#include "Console.h"

///////////////////////////////////////////////////////////////////////
//							Draw methods							 //
///////////////////////////////////////////////////////////////////////

Draw::Draw() {};

// Draw to point to console buffer
void Draw::Point(int x, int y, char character, byte color)
{
	Console console;
	console.WriteChar(x, y, character, color);
}

// Draw background
void Draw::Background(char character, byte color)
{
	for (int y = 0; y < screenHeight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			Point(x, y, character, color);
		}
	}
}

// Draw rectangle
void Draw::Rectangle(int x1, int y1, int x2, int y2, char character, byte color, bool outline)
{
	// If x1 or y1 is more than x2 or y2
	if (x2 < x1)
	{
		int x1Store = x2;
		x2 = x1;
		x1 = x1Store;
	}
	if (y2 < y1)
	{
		int y1Store = y2;
		y2 = y1;
		y1 = y1Store;
	}

	// Draw rectangle
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {

			// Rectangle fill
			if (outline == false)
				Point(x, y, character, color);
			// Rectangle Outline
			else if ((x == x1) || (y == y1) || (x == x2) || (y == y2))
				Point(x, y, character, color);
		}
	}
}
// Draw line
void Draw::Line(int x1, int y1, int x2, int y2, char character, byte color)
{
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1; dy = y2 - y1;
	dx1 = abs(dx); dy1 = abs(dy);
	px = 2 * dy1 - dx1;	py = 2 * dx1 - dy1;

	if (dy1 <= dx1)
	{
		if (dx >= 0) { x = x1; y = y1; xe = x2; }
		else { x = x2; y = y2; xe = x1; }

		Point(x, y, character, color);

		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0) px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			Point(x, y, character, color);
		}
	}
	else
	{
		if (dy >= 0) { x = x1; y = y1; ye = y2; }
		else { x = x2; y = y2; ye = y1; }

		Point(x, y, character, color);

		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0) py = py + 2 * dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1;
				else x = x - 1;
				py = py + 2 * (dx1 - dy1);
			}
			Point(x, y, character, color);
		}
	}
}

// Draw Parabola
void Draw::Parabola(int x1, int y1, bool center, float a, float b, float c, float accuracy, char character, byte color)
{
	{ for (float y = -yMid - y1; y < yMid - y1; y += accuracy)
		for (float x = -xMid + x1; x < xMid + x1; x += accuracy)
		{
			if (((a * pow(x, 2)) + (b * x) + c <= y + accuracy) && ((a * pow(x, 2)) + (b * x) + c >= y - accuracy))
			{
				if (center == false) Point(roundf(x) + x1, -roundf(y) - y1, character, color);
				else Point(roundf(x) + x1 + xMid, -roundf(y) - y1 + yMid, character, color);
			}
		}
	}
}