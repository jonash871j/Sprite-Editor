#include <sstream>
#include "EditorCreateGUI.h"
#include "EditorCore.h"

EditorCreateGui::EditorCreateGui() {};

// Draw GUI window
void EditorCreateGui::DrawGUIWindow(int xSize, int ySize, int xOffset, int yOffset, byte backgroundColor, byte forgrundColor)
{
	xOffsetMid = xOffset + xMid - (xSize / 2);
	yOffsetMid = yOffset + yMid - (ySize / 2);

	// Draw window
	mainGUI.DrawWindow(xSize, ySize, xOffset, yOffset, true, backgroundColor, forgrundColor);
	color = mainGUI.GetColor(backgroundColor, forgrundColor);
}

void EditorCreateGui::DrawGUILabel(int x, int y, std::string title, bool underline, byte customColor)
{
	// Draws the text inside of window
	console.WriteString(xOffsetMid + 3 + x, yOffsetMid + 3 + y, title, 0, customColor);

	// Draws a underline under the text
	if (underline == true)
		for (int i = 0; i < title.length() + 4; i++)
			console.WriteChar(xOffsetMid + 3 + i + x, yOffsetMid + 4 + y, HOR_LINE1X, customColor);
}

void EditorCreateGui::DrawGUINumber(int x, int y, int number, byte customColor)
{
	// Draws a Number inside of window
	console.WriteInt(xOffsetMid + 3 + x, yOffsetMid + 3 + y, number, 0, customColor);
}

void EditorCreateGui::DrawGUIChar(int x, int y, char character, byte customColor)
{
	// Draws a char inside of window
	console.WriteChar(xOffsetMid + 3 + x, yOffsetMid + 3 + y, character, customColor);
}

void EditorCreateGui::DrawGUIBox(int x1, int y1, int x2, int y2, byte customColor)
{
	// Draws a box inside of the window
	draw.Rectangle(xOffsetMid + x1 + 3, yOffsetMid + y1 + 3, xOffsetMid + x2 + 3, yOffsetMid + y2 + 3, 219, customColor, false);
}

void EditorCreateGui::DrawGUIMenu(int x, int y, std::string menuArray[], int arrayLength, int menuCus, int menuIdStart)
{
	// Loop used to draw menu array
	for (int i = 0; i < arrayLength; i++) {

		// Draw cursor when menu ID is equal to cursorpos
		if (i + menuIdStart == menuCus)
		{
			// Draws cursor
			console.WriteChar(2 + x + xOffsetMid, y + 3 + yOffsetMid + i, RT_ARROW, color);
			console.WriteString(4 + xOffsetMid + x, 3 + i + yOffsetMid + y, menuArray[i], 0, color);
		}
		else console.WriteString(3 + xOffsetMid + x, 3 + i + yOffsetMid + y, menuArray[i], 0, color);
	}
}


// Draw GUICheckBox
void EditorCreateGui::DrawGUICheckBoxMenu(int x, int y, int xCheckBox, std::string menuArray[], int arrayLength, int menuCus, int menuIdStart, int checkBoxVar)
{
	// Loop used to draw menu array
	for (int i = 0; i < arrayLength; i++) {

		// Draw cursor when menu ID is equal to cursorpos
		if (i + menuIdStart == menuCus)
		{
			// Draws cursor
			console.WriteChar(2 + x + xOffsetMid, y + 3 + yOffsetMid + i, RT_ARROW, color);

			// Draw one of the strings in the menu array, and offsets it by 1 on the x axis
			console.WriteString(4 + xOffsetMid + x, 3 + yOffsetMid + y + i, menuArray[i], 0, color);
		}
		// Draws the rest of the menus when cursor is equal to cursorpos
		else console.WriteString(3 + xOffsetMid + x, 3 + yOffsetMid + y + i, menuArray[i], 0, color);

		// Draws checkbox
		if (checkBoxVar == i) console.WriteChar(4 + xOffsetMid + x + xCheckBox, 3 + yOffsetMid + y + i, DOT, color); // Draws dot if checkbox is selected
		else console.WriteChar(4 + xOffsetMid + x + xCheckBox, 3 + yOffsetMid + y + i, ' ', color);					 // Draws space if checkbox is on selected
		console.WriteChar(3 + xOffsetMid + x + xCheckBox, 3 + yOffsetMid + y + i, '(', color);	 
		console.WriteChar(5 + xOffsetMid + x + xCheckBox, 3 + yOffsetMid + y + i, ')', color);	
	}
}

// Draws button
void EditorCreateGui::DrawGUIButton(int x, int y, std::string text, int menuCus, int menuIdStart)
{
	// Draws a black background around the button
	DrawGUIBox(x, y, x + 1 + text.length() + 2, y + 2, BLACK);

	// Draw double borders Horizontal
	draw.Rectangle(x + 4 + xOffsetMid, y + yOffsetMid + 3, x + text.length() + xOffsetMid + 5, y + yOffsetMid + 3, HOR_LINE2X, WHITE, false); // Top
	draw.Rectangle(x + 4 + xOffsetMid, y + yOffsetMid + 5, x + text.length() + xOffsetMid + 5, y + yOffsetMid + 5, HOR_LINE2X, WHITE, false); // Buttom

	// Draw double borders Vertical
	console.WriteChar(x + 3 + xOffsetMid, y + yOffsetMid + 4, VER_LINE2X, WHITE);
	console.WriteChar(x + 6 + xOffsetMid + text.length(), y + yOffsetMid + 4, VER_LINE2X, WHITE);

	// Draw double corner left
	console.WriteChar(x + 3 + xOffsetMid, y + yOffsetMid + 3, UP_LFCOR2X, WHITE);
	console.WriteChar(x + 3 + xOffsetMid, y + yOffsetMid + 5, LW_LFCOR2X, WHITE);

	// Draw double corner right
	console.WriteChar(x + 6 + xOffsetMid + text.length(), y + yOffsetMid + 3, UP_RTCOR2X, WHITE);
	console.WriteChar(x + 6 + xOffsetMid + text.length(), y + yOffsetMid + 5, LW_RTCOR2X, WHITE);

	// Draw button text
	DrawGUILabel(x + 2, y + 1, text, false, WHITE);

	// Draw cursor when menu ID is equal to cursorpos
	if (menuCus == menuIdStart)
	{
		console.WriteChar(x + 4 + xOffsetMid, y + yOffsetMid + 4, RT_ARROW, WHITE);
		console.WriteChar(x + 5 + xOffsetMid + text.length(), y + yOffsetMid + 4, LF_ARROW, WHITE);
	}
}

// Textbox for strings
std::string EditorCreateGui::DrawGUITextBoxString(int x, int y, int characterLimit, std::string stringText, byte customColor, byte customColorSelected, int menuCus, int menuIdStart)
{
	// When textbox is entered
	if ((textBoxMode == true) && (menuCus == menuIdStart))
	{
		// Exits out of text box when enter or escape is pressed
		if ((input.keyPressed(VK_RETURN)) || input.keyPressed(VK_ESCAPE))
		{ sound.Play(snd::CLICK); textBoxMode = false; }

		// New string input
		stringText += console.ReadString(true, true);					   // This takes the input and puts it into a string, and also is set to both allow numbers and letters in the string.
		stringText = console.ReadStringConfig(stringText, characterLimit); // This puts a chracter limit to the string

		// Draws the string input to screen
		DrawGUILabel(x, y, stringText, false, customColorSelected);
	}
	// When textbox not is entered
	else
	{
		// This makes sure that the textbox isn't empty
		if (stringText == "") stringText = "newsprite";

		// This draws the string to the screen
		DrawGUILabel(x, y, stringText, false, customColor);
	}
	return stringText;
}

// Textbox for integers
int EditorCreateGui::DrawGUITextBoxInt(int x, int y, int characterLimit, int maxNumber, int number, byte customColor, byte customColorSelected, int menuCus, int menuIdStart)
{
	// When textbox is entered
	if ((textBoxMode == true) && (menuCus == menuIdStart))
	{
		// Exits out of text box when enter or escape is pressed
		if ((input.keyPressed(VK_RETURN)) || input.keyPressed(VK_ESCAPE))
		{ sound.Play(snd::CLICK); textBoxMode = false; }
	
		// New string input
		stringNumber += console.ReadString(true, false);  					   // This takes the input and puts it into a string, and also is set to only allow numbers in the string.
		stringNumber = console.ReadStringConfig(stringNumber, characterLimit); // This puts a chracter limit to the string

		// Draws the string input to screen
		DrawGUILabel(x, y, stringNumber, false, customColorSelected);

		// Converts string to int
		std::istringstream iss(stringNumber);
		iss >> number;
	}
	// When textbox not is entered
	else
	{
		// This makes sure that the int isn't higher or lower than the max. or min. number allowed.
		if (number > maxNumber) number = maxNumber;
		if (number == 0) number = 1;

		// This draws  the number to the screen
		DrawGUINumber(x, y, number, customColor);
	}
	return number;
}