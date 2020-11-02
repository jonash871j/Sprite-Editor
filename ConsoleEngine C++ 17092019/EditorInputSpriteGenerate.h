#pragma once
namespace editspr
{
	void GenerateSprite()
	{
		// Deletes old array
		for (int i = 0; i < height; i++)
			delete[] spriteArrayCharacter[i];

		for (int i = 0; i < height; i++)
			delete[] spriteArrayColor[i];

		delete[] spriteArrayCharacter;
		delete[] spriteArrayColor;

		// Set new sprite size
		spriteWidth = spriteGuiWidth;
		height = spriteGuiHeight;

		// Sets the name of sprite
		spriteName = spriteGuiName;

		// Defines the size of the arrays
		spriteArrayCharacter = new char* [spriteHeight];
		for (int i = 0; i < spriteHeight; i++)
			spriteArrayCharacter[i] = new char[spriteWidth];

		spriteArrayColor = new char* [spriteHeight];
		for (int i = 0; i < spriteHeight; i++)
			spriteArrayColor[i] = new char[spriteWidth];

		// Sets arrays to nothing
		for (int y = 0; y < spriteHeight; y++) {
			for (int x = 0; x < spriteWidth; x++) {
				spriteArrayCharacter[y][x] = char(0);
				spriteArrayColor[y][x] = char(0);
			}
		}
	}
}