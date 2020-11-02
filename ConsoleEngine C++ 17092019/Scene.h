#pragma once
#include "EngineCore.h"
#include "Console.h"
#include "Object.h"
#include <vector>

class Scene
{
private:
	// Sprite array
	Object spriteArray[255];

	void DeleteArrays();

public:
	// Variables
	char** mapArray;
	int cellWidth, mapWidth;
	int cellHeight, mapHeight;

	Scene();

	// Scene
	void ImportMap(std::string fileName);

	void NewMap(int mapWidth, int mapHeight);

	void ObjectDimensions(int cellWidth, int cellHeight);
	
	void ObjectId(byte charId, Object sprite);

	void DrawMap(int x, int y);

	void DrawDebugMap(int x, int y, byte color);
};

