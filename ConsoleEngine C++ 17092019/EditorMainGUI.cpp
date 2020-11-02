#include "EditorMainGUI.h"
#include "EditorCore.h"

EditorMainGUI::EditorMainGUI() {};

// Mixing the forgrund and background color
byte EditorMainGUI::GetColor(byte backgroundColor, byte forgrundColor)
{
	byte color;
	byte colorCobination;
	for (byte i = 0; i < 16; i++) {
		colorCobination = i * 16;
		if (backgroundColor == i) color = colorCobination + forgrundColor;
	}
	return color;
}

// Draws window
void EditorMainGUI::DrawWindow(int xSize, int ySize, int xOffset, int yOffset, bool center, byte backgroundColor, byte forgrundColor)
{
	// Mixing the forgrund and background color
	byte color = GetColor(backgroundColor, forgrundColor);

	int xWindow = xSize + xOffset;
	int yWindow = ySize + yOffset;

	// Places the window in the center of screen
	if (center == true) { xWindow = xOffset + xMid + xSize / 2; yWindow = yOffset + yMid + ySize / 2; }

	// Draw background
	draw.Rectangle(xWindow - xSize + 1, yWindow - ySize + 1, xWindow + 2, yWindow + 2, BLOCKFULL, BLACK, false);  //Window background 3D effect
	draw.Rectangle(xWindow - xSize, yWindow - ySize, xWindow, yWindow, BLOCKFULL, backgroundColor, false);		  //Window background

	// Draw borders vertical
	draw.Rectangle(xWindow - xSize, yWindow - ySize + 1, xWindow - xSize, yWindow, VER_LINE1X, color, false); //Left
	draw.Rectangle(xWindow + 1, yWindow - ySize + 1, xWindow + 1, yWindow, VER_LINE1X, color, false);		  //Right

	// Draw borders Horizontal
	draw.Rectangle(xWindow - xSize + 1, yWindow - ySize, xWindow, yWindow - ySize, HOR_LINE1X, color, false); //Top
	draw.Rectangle(xWindow - xSize + 1, yWindow + 1, xWindow, yWindow + 1, HOR_LINE1X, color, false);		  //Buttom

	// Draw corners left
	draw.Point(xWindow - xSize, yWindow - ySize, UP_LFCOR1X, color); //Top
	draw.Point(xWindow - xSize, yWindow + 1, LW_LFCOR1X, color);	 //Buttom

	// Draw corners right		
	draw.Point(xWindow + 1, yWindow - ySize, UP_RTCOR1X, color);	 //Top
	draw.Point(xWindow + 1, yWindow + 1, LW_RTCOR1X, color);		 //Buttom
}
