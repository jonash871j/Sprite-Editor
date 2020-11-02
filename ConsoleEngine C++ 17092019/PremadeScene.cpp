#include "PremadeScene.h"
#include "Console.h"
#include "Draw.h"

///////////////////////////////////////////////////////////////////////
//						PremadeScene methods						 //
///////////////////////////////////////////////////////////////////////

PremadeScene::PremadeScene() {};


// Coordinate system
void PremadeScene::AddCoordinateSystem(int xCoord, int yCoord, byte colorGrid, byte colorLines, byte colorNumbers, bool showNumbers, bool showGrid)
{
	Draw draw;
	Console console;
	
	xCoord = xMid - xCoord;
	yCoord = yMid - yCoord;

	// Background
	if (showGrid == true) 
		 draw.Background(254, colorGrid);
	else draw.Background(219, colorGrid);

	// Y axis
	for (int y = 0; y < screenHeight; y++)
	{
		draw.Point(xCoord, y, 195, colorLines);
		if (showNumbers == true) 
			console.WriteInt(xCoord + 1, y, y - yCoord, LEFT_TO_RIGHT, colorNumbers);

		console.WriteString(xCoord - 2, 0, "+Y", LEFT_TO_RIGHT, colorLines);
		console.WriteString(xCoord - 2, screenHeight - 1, "-Y", LEFT_TO_RIGHT, colorLines);
	}

	// X axis
	for (int x = 0; x < screenWidth; x++)
	{
		draw.Point(x, yCoord, 193, colorLines);
		if ((x != xCoord) && (showNumbers == true))
			console.WriteInt(x, yCoord - 1, x - xCoord, BUTTOM_TO_TOP, colorNumbers);

		console.WriteString(0, yCoord + 1, "-X", LEFT_TO_RIGHT, colorLines);
		console.WriteString(screenWidth - 2, yCoord + 1, "+X", LEFT_TO_RIGHT, colorLines);
	}
	// Center
	draw.Point(xCoord, yCoord, 197, colorLines);
}