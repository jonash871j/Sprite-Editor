#include "Scene.h"
///////////////////////////////////////////////////////////////////////
//							Scene methods							 //
///////////////////////////////////////////////////////////////////////

Scene::Scene() {};

// Private - Delete arrays
void Scene::DeleteArrays()
{
	for (int i = 0; i < cellHeight; i++)
		delete[] mapArray[i];

	delete[] mapArray;
}

void Scene::ImportMap(std::string fileName)
{
	std::ifstream inFile;
	inFile.open("./map/" + fileName + ".acspr");
	if (inFile.fail())
	{
		Console console;

		// Error console
		console.WriteString(0, 0, fileName + ".map", LEFT_TO_RIGHT, D_RED);
		console.WriteString(0, 2, "Please check if wrong file name was entered or if", LEFT_TO_RIGHT, RED);
		console.WriteString(0, 3, "the map file isn't located in the project directory...", LEFT_TO_RIGHT, RED);
		console.Update();

		// Error messagebox
		const int result = MessageBox(NULL, "Error, failed to import map!", "Console Engine", MB_ABORTRETRYIGNORE | MB_ICONERROR);
		switch (result)
		{
		case IDABORT : exit(0); break; // Terminates console
		case IDRETRY : return ; break; // returns out of the method
		case IDIGNORE: return ; break; // returns out of the method
		}
	}
	DeleteArrays();

	//Reads the sprite width and sprite height
	inFile >> mapWidth;
	inFile.ignore(1, '\n');
	inFile >> mapHeight;
	inFile.ignore(1, '\n');

	//Defines the size of the arrays
	mapArray = new char* [mapHeight];
	for (int i = 0; i < mapHeight; i++)
		mapArray[i] = new char[mapWidth];

	//Reads the map array
	for (int i = 0; i < mapHeight; i++)
	{
		inFile.read(mapArray[i], mapWidth);
		inFile.ignore(1, '\n');
	}
	inFile.close();
}
#pragma endregion

// Map object dimensions
void Scene::ObjectDimensions(int cellWidth, int cellHeight)
{
	this->cellWidth = cellWidth;
	this->cellHeight = cellHeight;
}

// Map dimensions
void Scene::NewMap(int mapWidth, int mapHeight)
{
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;

	//Defines the size of the arrays
	mapArray = new char* [mapHeight];
	for (int i = 0; i < mapHeight; i++)
		mapArray[i] = new char[mapWidth];
}

// Object id
void Scene::ObjectId(byte charId, Object sprite)
{
	//spriteArray[charId] = sprite;
}

// Draw map
void Scene::DrawMap(int x, int y)
{
	for (int y1 = 0; y1 < mapHeight; y1++) {
		for (int x1 = 0; x1 < mapWidth; x1++) {
			for (int i = 32; i < 127; i++) {
				if (mapArray[y1][x1] == char(i)) spriteArray[i].SpriteDraw((x1 * cellWidth) + x, (y1 * cellHeight) + y);
			}
		}
	}
}

// Draw debug map
void Scene::DrawDebugMap(int x, int y, byte color)
{
	Console console;
	for (int y1 = 0; y1 < mapHeight; y1++) {
		for (int x1 = 0; x1 < mapWidth; x1++) {
			console.WriteChar(x1 + x, y1 + y, mapArray[y1][x1], color);
		}
	}
}