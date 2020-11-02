#pragma once
#include "EngineCore.h"
#include "Console.h"
#include "Input.h"
#include "Draw.h"
#include "Sound.h"
#include "EditorMainGui.h"

class EditorCreateGui
{
private:
	// Create objects
	Console console;
	Input input;
	Draw draw;
	Sound sound;
	EditorMainGUI mainGUI;

public:
	std::string stringNumber;
	byte color;
	int xOffsetMid, yOffsetMid;
	bool textBoxMode = false;

	EditorCreateGui();

	void DrawGUIWindow(int xSize, int ySize, int xOffset, int yOffset, byte backgroundColor, byte forgrundColor);

	void DrawGUILabel(int x, int y, std::string title, bool underline, byte customColor);

	void DrawGUINumber(int x, int y, int number, byte customColor);

	void DrawGUIChar(int x, int y, char character, byte customColor);

	void DrawGUIBox(int x1, int y1, int x2, int y2, byte customColor);

	void DrawGUIMenu(int x, int y, std::string menuArray[], int arrayLength, int menuCus, int menuIdStart);

	void DrawGUICheckBoxMenu(int x, int y, int xCheckBox, std::string menuArray[], int arrayLength, int menuCus, int menuIdStart, int checkBoxVar);

	void DrawGUIButton(int x, int y, std::string text, int menuCus, int menuIdStart);

	std::string DrawGUITextBoxString(int x, int y, int characterLimit, std::string stringText, byte customColor, byte customColorSelected, int menuCus, int menuIdStart);

	int DrawGUITextBoxInt(int x, int y, int characterLimit, int maxNumber, int number, byte customColor, byte customColorSelected, int menuCus, int menuIdStart);
};