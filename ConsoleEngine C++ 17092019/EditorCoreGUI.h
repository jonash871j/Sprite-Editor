#pragma once
#include "EditorMainGUI.h"
#include "EngineCore.h"
#include "Console.h"
#include "Draw.h"

class EditorMainGUI
{
private:
	Console console;
	Draw draw;

public:
	EditorMainGUI();

	// Mixing the forgrund and background color
	byte GetColor(byte backgroundColor, byte forgrundColor);

	// Draws window
	void DrawWindow(int xSize, int ySize, int xOffset, int yOffset, bool center, byte backgroundColor, byte forgrundColor);
};

