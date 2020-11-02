#pragma once
#pragma once
namespace editspr
{
	// Load file structure for ACSPR ************************************************************************************
	bool LoadACSPR()
	{
		std::ifstream inFile;
		inFile.open(load::file);
		if (inFile.fail()) return false;

		//Deletes old array
		Delete();

		//Reads the sprite width and sprite height
		int widthCheck = 0;
		int heightCheck = 0;
		inFile >> widthCheck;
		inFile.ignore(1, '\n');
		inFile >> heightCheck;
		inFile.ignore(1, '\n');
		if (inFile.fail()) return false;
		width = widthCheck;
		height = heightCheck;

		//Defines the size of the arrays
		arrayCharacter = new char* [height];
		for (int i = 0; i < height; i++)
			arrayCharacter[i] = new char[width];

		arrayColor = new char* [height];
		for (int i = 0; i < height; i++)
			arrayColor[i] = new char[width];

		//Reads the sprite- and color array
		for (int i = 0; i < height; i++){
			inFile.read(arrayCharacter[i], width);
			inFile.ignore(1, '\n');
		}
		inFile.ignore(1, '\n');

		for (int i = 0; i < height; i++){
			inFile.read(arrayColor[i], width);
			inFile.ignore(1, '\n');
		}
		inFile.close();

		// Converts acspr over to acxspr proberly
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if ((arrayCharacter[y][x] == char(0)) || (arrayCharacter[y][x] == char(32)) || (arrayCharacter[y][x] == char(255))) {
					arrayCharacter[y][x] = char(0);
					arrayColor[y][x] = char(0);
				}
			}
		}
		return true;
	}
}