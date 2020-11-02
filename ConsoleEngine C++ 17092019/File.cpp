#include "File.h"

///////////////////////////////////////////////////////////////////////
//							File methods							 //
///////////////////////////////////////////////////////////////////////

File::File() {};

void File::Create(std::string fileName, std::string formatName)
{
	this->fileName = fileName;
	this->formatName = formatName;

	std::fstream file(fileName + formatName, std::ios_base::in | std::ios_base::out | std::ios_base::app);
}

void File::SaveInt(std::string description, int varInt, int lineNumber)
{

}