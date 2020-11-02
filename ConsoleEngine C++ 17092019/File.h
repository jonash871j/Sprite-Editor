#pragma once
#include "EngineCore.h"
#include <fstream>

class File
{
private:
	std::string fileName;
	std::string formatName;
	std::fstream stFile;

public:
	File();

	void Create(std::string fileName, std::string formatName);

	void SaveInt(std::string description, int varInt, int lineNumber);


};

