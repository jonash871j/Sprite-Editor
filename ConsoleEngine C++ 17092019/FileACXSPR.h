#pragma once
namespace editspr
{
	char fileformat[3];
	// Save file structure for ACXSPR ************************************************************************************
	void SaveACXSPR(std::string filename)
	{
		// Opens file
		std::ofstream outFile;
		outFile.open("./sprite/" + filename + ".acxspr");

		// Write sprite infomation to file
		outFile << "ACX" << width << ' ' << height << ' ';

		//Write characters array to file
		for (int i = 0; i < height; i++)
			outFile.write(arrayCharacter[i], width);

		//Write color array to file
		for (int i = 0; i < height; i++)
			outFile.write(arrayColor[i], width);
		outFile.close();
	}

	// Load file structure for ACXSPR ************************************************************************************
	bool LoadACXSPR()
	{
		// Opens and checks if file is valid
		std::ifstream inFile;
		inFile.open(load::file);
		if (inFile.fail()) return false;

		// Checks the filefomat if it's valid
		for (int i = 0; i < 3; i++)
			fileformat[i] = '0';
		inFile.read(fileformat, 3);
		std::string fileCheck(fileformat);
		if (fileCheck != "ACX") return false;

		//Deletes old array
		Delete();

		// Reads sprite infomation
		inFile >> width;
		inFile.ignore(1, ' ');
		inFile >> height;
		inFile.ignore(1, ' ');

		// Generates new arrays
		NewArrays();

		// Reads the chracter array
		for (int i = 0; i < height; i++)
			inFile.read(arrayCharacter[i], width);

		// Reads the color array
		for (int i = 0; i < height; i++)
			inFile.read(arrayColor[i], width);
		inFile.close();
		return true;
	}
}