#pragma once
namespace editspr
{
	int returnCounter = 0;
	void Fill(int x, int y, char brush, char brushToCheck, bool fillCharacterElseColor)
	{
		// Checks if brush isn't the as the brush to check
		if ((brush == brushToCheck) || (returnCounter >= 2048)) {
			return;
		} returnCounter += 1;
		// Check at x axis
		for (int x1 = -1; x1 < 2; x1++) {
			if ((x1 + x >= 0) && (x1 + x < width)) { // Checks if array is out of bounds
				if (fillCharacterElseColor == true) {
					if (arrayCharacter[y][x1 + x] == char(brushToCheck)) { // Checks the brush to check

							// Writes new charater and color to arrays
						arrayCharacter[y][x1 + x] = brush;
						arrayColor[y][x1 + x] = (colorBackground * 16) + colorForegrund;

						// Calls the function again 
						Fill(x1 + x, y, brush, brushToCheck, fillCharacterElseColor);
					}
				}
				else {
					if (arrayColor[y][x1 + x] == char(brushToCheck)) { // Checks the brush to check
						arrayCharacter[y][x1 + x] = charCusPos + charBarPos;
						arrayColor[y][x1 + x] = brush;

						// Calls the function again 
						Fill(x1 + x, y, brush, brushToCheck, fillCharacterElseColor);
					}
				}
			}
		}

		// Check at y axis
		for (int y1 = -1; y1 < 2; y1++) {
			if ((y1 + y >= 0) && (1 + y < height)) { // Checks if array is out of bounds
				if (fillCharacterElseColor == true) {
					if (arrayCharacter[y1 + y][x] == char(brushToCheck)) { // Checks the brush to check

						// Writes new charater and color to arrays
						arrayCharacter[y1 + y][x] = brush;
						arrayColor[y1 + y][x] = (colorBackground * 16) + colorForegrund;

						// Calls the function again 
						Fill(x, y1 + y, brush, brushToCheck, fillCharacterElseColor);
					}
				}
				else {
					if (arrayColor[y1 + y][x] == char(brushToCheck)) { // Checks the brush to check
						arrayCharacter[y1 + y][x] = charCusPos + charBarPos;
						arrayColor[y1 + y][x] = brush;

						// Calls the function again 
						Fill(x, y1 + y, brush, brushToCheck, fillCharacterElseColor);
					}
				}
			}
		}
		return;
	}

	void WorkspaceEvents()
	{
		// Cursor movement
		if ((input.keyPressed(VK_LEFT)) && (xPos > 0)) xPos -= 1;
		if ((input.keyPressed(VK_RIGHT)) && (xPos < width - 1)) xPos += 1;
		if ((input.keyPressed(VK_UP)) && (yPos > 0)) yPos -= 1;
		if ((input.keyPressed(VK_DOWN)) && (yPos < height - 1)) yPos += 1;

		// Draw
		if (input.keyState(VK_SPACE))
		{
			arrayCharacter[yPos][xPos] = charCusPos + charBarPos;
			arrayColor[yPos][xPos] = (colorBackground * 16) + colorForegrund;
		}

		// Fill color
		returnCounter = 0;
		if (input.keyPressed(VK_MENU))
			Fill(xPos, yPos, char((colorBackground * 16) + colorForegrund), arrayColor[yPos][xPos], false);

		// Fill character
		if (input.keyPressed('Z'))
			Fill(xPos, yPos, charCusPos + charBarPos, arrayCharacter[yPos][xPos], true);

		// Erase
		if (input.keyState(VK_DELETE))
		{
			arrayCharacter[yPos][xPos] = char(0);
			arrayColor[yPos][xPos] = char(0);
		}

		// Change character brush
		if (input.keyPressed(VK_END))
		{
			if (charCusPos > 0) charCusPos -= 1;
			else charBarPos -= 1;
		}
		if (input.keyPressed(VK_HOME))
		{
			if (charCusPos <= (screenWidth / 2) - 2) charCusPos += 1;
			else charBarPos += 1;
		}

		// Change color
		for (int i = 48; i < 58; i++)
		{
			if (input.keyPressed(i))
			{
				if (input.keyState(VK_SHIFT)) colorBackground = i - 48;
				else colorForegrund = i - 48;
			}
		}
		for (int i = 65; i < 71; i++)
		{
			if (input.keyPressed(i))
			{
				if (input.keyState(VK_SHIFT)) colorBackground = i - 55;
				else colorForegrund = i - 55;
			}
		}
	}
}