#pragma once
#include "EngineCore.h"

class PremadeScene
{
public:
	PremadeScene();

	// Scenes
	void AddCoordinateSystem(int xCoord, int yCoord, byte colorGrid, byte colorLines, byte colorNumbers, bool showNumbers, bool showGrid);
};

