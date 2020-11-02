#pragma once
#include "EngineCore.h"
#include "Console.h"
#include <fstream>

class Object
{
private:
	Console console;
	std::ifstream inFile;
	char fileformat[3] = { 0 };
	bool endState = false;
	char** spriteArray;
	char** spriteColorArray;

	void DeleteArrays();

public:
	int xPos, yPos;
	int spriteWidth, spriteHeight;

	Object();

	// Import
	void ImportSprite(std::string fileName);

	// Sprite Draw
	void SpriteDraw(int posX, int posY);

	void SpriteDrawAdvanced(int posX, int posY, bool flip, int rotate);

	void SpriteDrawBackground();

	// Object events
	bool Collide(Object object, int xOffset, int yOffset);
};