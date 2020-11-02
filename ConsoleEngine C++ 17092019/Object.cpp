#include "EngineCore.h"
#include "Object.h"

///////////////////////////////////////////////////////////////////////
//						Object methods								 //
///////////////////////////////////////////////////////////////////////

Object::Object() {};

// Private - Delete arrays
void Object::DeleteArrays()
{
	for (int i = 0; i < spriteHeight; i++)
		delete[] spriteArray[i];

	for (int i = 0; i < spriteHeight; i++)
		delete[] spriteColorArray[i];

	delete[] spriteArray;
	delete[] spriteColorArray;
}

// Import sprite
void Object::ImportSprite(std::string fileName)
{
	// Opens and checks if file is valid
	inFile.open(fileName + ".acxspr");
	if (inFile.fail())
	{
		// Error console
		console.WriteString(0, 0, fileName + ".acxspr", LEFT_TO_RIGHT, D_RED);
		console.WriteString(0, 2, "Please check if wrong file name was entered or if", LEFT_TO_RIGHT, RED);
		console.WriteString(0, 3, "the sprite file isn't located in the project directory...", LEFT_TO_RIGHT, RED);
		console.Update();

		// Error messagebox
		const int result = MessageBox(NULL, "Error, failed to import sprite!", "Console Engine", MB_ABORTRETRYIGNORE | MB_ICONERROR);
		switch (result)
		{
		case IDABORT: exit(0); break; // Terminates console
		case IDRETRY: return; break; // returns out of the method
		case IDIGNORE: return; break; // returns out of the method
		}
	}
	DeleteArrays();

	// Reads sprite infomation
	inFile.read(fileformat, 3);
	inFile >> spriteWidth;
	inFile.ignore(1, ' ');
	inFile >> spriteHeight;

	// Checks the filefomat if it's valid
	std::string formatCheck(fileformat);
	if (formatCheck != "ACX") return;

	// Creates new chracter array for sprite
	spriteArray = new char* [spriteHeight];
	for (int i = 0; i < spriteHeight; i++)
		spriteArray[i] = new char[spriteWidth];

	// Creates new color array for sprite
	spriteColorArray = new char* [spriteHeight];
	for (int i = 0; i < spriteHeight; i++)
		spriteColorArray[i] = new char[spriteWidth];

	// Reads the chracter array
	for (int i = 0; i < spriteHeight; i++)
		inFile.read(spriteArray[i], spriteWidth);

	// Reads the color array
	for (int i = 0; i < spriteHeight; i++)
		inFile.read(spriteColorArray[i], spriteWidth);
	inFile.close();
	if (endState == true) DeleteArrays();
}
#pragma endregion

// Draw sprite to screen
void Object::SpriteDraw(int x, int y)
{
	xPos = x;
	yPos = y;

	for (int y1 = 0; y1 < spriteHeight; y1++) {
		for (int x1 = 0; x1 < spriteWidth; x1++) {
			if ((y + y1 >= 0) && (y + y1 < screenHeight) && (x + x1 >= 0) && (x + x1 < screenWidth) && (spriteArray[y1][x1] != char(0)))
			{
				console.WriteChar(x1 + x, y1 + y, spriteArray[y1][x1], spriteColorArray[y1][x1]);
			}
		}
	}
}

// Draw sprite to screen with more options
void Object::SpriteDrawAdvanced(int posX, int posY, bool flip, int rotate)
{
	for (int y = 0; y < spriteHeight; y++) {
		for (int x = 0; x < spriteWidth; x++) {
			if ((posY + y >= 0) && (posY + y < screenHeight) && (posX + x >= 0) && (posX + x < screenWidth) && (spriteArray[y][x] != ' '))
			{
				if (flip == false)
				{
					if (rotate == 0) console.WriteChar(x + posX, y + posY, spriteArray[y][x], spriteColorArray[y][x]);
					if (rotate == 180) console.WriteChar((-x + spriteWidth - 1) + posX, (-y + spriteHeight - 1) + posY, spriteArray[y][x], spriteColorArray[y][x]);

					if (rotate == 90) console.WriteChar((-y + spriteHeight - 1) + posX, x + posY, spriteArray[y][x], spriteColorArray[y][x]);
					if (rotate == 270) console.WriteChar(y + posX, (-x + spriteWidth - 1) + posY, spriteArray[y][x], spriteColorArray[y][x]);
				}
				else
				{
					if (rotate == 0) console.WriteChar(x + posX, (-y + spriteHeight - 1) + posY, spriteArray[y][x], spriteColorArray[y][x]);
					if (rotate == 180) console.WriteChar((-x + spriteWidth - 1) + posX, y + posY, spriteArray[y][x], spriteColorArray[y][x]);

					if (rotate == 90) console.WriteChar(y + posX, x + posY, spriteArray[y][x], spriteColorArray[y][x]);
					if (rotate == 270) console.WriteChar((-y + spriteHeight - 1) + posX, (-x + spriteWidth - 1) + posY, spriteArray[y][x], spriteColorArray[y][x]);
				}
					
			}
		}
	}
}

// Draw sprite as background to screen
void Object::SpriteDrawBackground()
{
	for (int bY = 0; bY < floor(screenHeight / spriteHeight); bY++) {
		for (int bX = 0; bX < floor(screenWidth / spriteWidth); bX++) {
			for (int y = 0; y < spriteHeight ; y++) {
				for (int x = 0; x < spriteWidth; x++) {
					if (spriteArray[y][x] != ' ')
					{
						console.WriteChar(x + (bX * spriteWidth), y + (bY * spriteHeight), spriteArray[y][x], spriteColorArray[y][x]);
					}
				}
			}
		}
	}
}

// Check collision between to Objects
bool Object::Collide(Object object, int xOffset, int yOffset)
{
	for (int y = 0; y < spriteHeight; y++){
		for (int x = 0; x < spriteWidth; x++){
			if ((xPos + x  + xOffset >= object.xPos) && (xPos + x + xOffset < object.xPos + object.spriteWidth) && 
				(yPos + y + yOffset >= object.yPos) && (yPos + y + yOffset < object.yPos + object.spriteHeight))
				return true;
		}
	}
	return false;
}

