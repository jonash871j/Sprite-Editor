#pragma once
#include "EditorVariables.h"
Object button_ok;

void drawMainBar(byte mainBarSpace)
{
	// Calculates the array length
	byte mainBarLength = (sizeof(mainBar) / 28);

	// Checks if the cursor is not more or less than the mainbar array length
	if (mainBarCusPos < 0) mainBarCusPos = 3;
	if (mainBarCusPos >= mainBarLength) mainBarCusPos = 0;

	// Draws the the mainbar
	characterLength = 0; // Reset
	draw.Rectangle(0, 0, screenWidth, 0, 219, WHITE, false);
	for (int i = 0; i < mainBarLength; i++) {
		for (int j = 0; j < mainBar[i].length(); j++) {
			if ((mainBarCusPos == i) && (menuState == MAINBAR)) console.WriteString(characterLength, 0, mainBar[i], 0, WHITE);
			else if ((mainBarCusPos == i) && (menuState == TOOL_MENU)) console.WriteString(characterLength, 0, mainBar[i], 0, 31); 
			else console.WriteString(characterLength, 0, mainBar[i], 0, 240); 
		}
		// Caluclates the space between each character in the string array
		characterLength += mainBar[i].length() + mainBarSpace; 
	}
}

void drawFooter(std::string footerArray[], byte mainBarSpace, byte arrayLength)
{
	// Draws the footer
	characterLength = 0;
	draw.Rectangle(0, screenHeight - 1, screenWidth, screenHeight - 1, 0, 0, false);
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < footerArray[i].length(); j++) 
			console.WriteString(characterLength, screenHeight-1, footerArray[i], 0, WHITE);

		// Caluclates the space between each character in the string array
		characterLength += footerArray[i].length() + mainBarSpace;
	}
}

void DrawOKMessageBox(int xSize, int ySize, int newMenuState, byte backgroundColor, byte forgrundColor, std::string messageLine1, std::string messageLine2, std::string messageLine3)
{
	if (menuState == MESSAGEBOX)
	{
		// Mixing the forgrund and background color
		byte color = mainGUI.GetColor(backgroundColor, forgrundColor);

		// Draw window
		mainGUI.DrawWindow(xSize, ySize, 0, 0, true, backgroundColor, forgrundColor);

		// Draw message
		console.WriteString(xMid - (messageLine1.length() / 2), yMid - (ySize / 2) + 6, messageLine1, 0, color);
		console.WriteString(xMid - (messageLine2.length() / 2), yMid - (ySize / 2) + 7, messageLine2, 0, color);
		console.WriteString(xMid - (messageLine3.length() / 2), yMid - (ySize / 2) + 8, messageLine3, 0, color);

		// Draw OK button
		button_ok.SpriteDraw(xMid - 3, yMid + (ySize / 2) - 3);

		// Updates screen
		console.Update();

		// Pauses the screen until button is pressed
		while (!input.keyPressed(VK_RETURN)) Sleep(10);
		sound.Play(snd::CLICK);
		menuState = newMenuState;
	}
}

namespace editspr
{
	void NewArrays()
	{
		// Creates new chracter array for sprite
		arrayCharacter = new char* [height];
		for (int i = 0; i < height; i++)
			arrayCharacter[i] = new char[width];

		// Creates new color array for sprite
		arrayColor = new char* [height];
		for (int i = 0; i < height; i++)
			arrayColor[i] = new char[width];

		// Sets arrays to null
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				arrayCharacter[y][x] = char(0);
				arrayColor[y][x] = char(0);
			}
		}
	}

	void Delete()
	{
		// Deletes old array
		for (int i = 0; i < height; i++)
			delete[] arrayCharacter[i];

		for (int i = 0; i < height; i++)
			delete[] arrayColor[i];

		delete[] arrayCharacter;
		delete[] arrayColor;
	}
}

class ToolMenu
{
private:
	byte color;
	int xOffset, yOffset;
	int yStartNext;
	int yLineStartNext;
	int xSize = 0;
	int ySize = 0;

public:
	void DrawMenu(int xSize, int xOffset, int yOffset, byte backgroundColor, byte forgrundColor)
	{
		this->xOffset = xOffset;
		this->yOffset = yOffset;
		this->xSize = xSize;

		yStartNext = 0;
		yLineStartNext = 0;

		if (menuState == TOOL_MENU)
		{
			// Go back to mainbar
			if ((toolBarCusPos < 0) && (menuState == TOOL_MENU))
			{ sound.Play(snd::CLICK_BACKWARD); menuState = MAINBAR; toolBarCusPos = 0; }

			// Draw window
			mainGUI.DrawWindow(xSize, ySize, xOffset, yOffset, false, backgroundColor, forgrundColor);
			color = mainGUI.GetColor(backgroundColor, forgrundColor);
		}
	}
	void AddMenu(std::string menuArray[], int menuArrayLength)
	{
		if (menuState == TOOL_MENU)
		{
			// Draw line between menus
			if (yStartNext != 0)
				draw.Rectangle(1 + xOffset, yLineStartNext + yStartNext + yOffset, xSize + xOffset, yLineStartNext + yStartNext + yOffset, 196, color, false);

			// Draw menu array
			for (int i = 0; i < menuArrayLength; i++) {
				if (toolBarCusPos == i + yStartNext)
				{
					console.WriteChar(1 + xOffset, 1 + i + yOffset + yStartNext + yLineStartNext, 16, color);
					console.WriteString(2 + xOffset, 1 + i + yOffset + yStartNext + yLineStartNext, " " + menuArray[i], 0, color);
				}
				else console.WriteString(2 + xOffset, 1 + i + yOffset + yStartNext + yLineStartNext, menuArray[i], 0, color);
			}

			yStartNext += menuArrayLength;
			ySize = yStartNext + yLineStartNext;
			yLineStartNext += 1;
		}
	}
	void stopMenu()
	{
		if (toolBarCusPos >= yStartNext) toolBarCusPos = yStartNext - 1;
	}
};