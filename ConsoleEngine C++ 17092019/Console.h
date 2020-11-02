#pragma once
#include "EngineCore.h"
#include <vector>

class Console
{
private:
	// Used to convert integer into a integer array
	std::vector <int> integerToArray(int x);

	void UpdateWindowSize(bool GetScreenBufferInfo);

	void FpsGetCurrent();

	int fps, fpsCount, fpsSubtrack;

public:
	int colorPlalette[16];
	int fpsCurrent;

	Console();

	// Console
	void Startup();

	void Update();

	void WriteChar(int x, int y, char character, byte color);

	void WriteString(int x, int y, std::string text, byte direction, byte color);

	void WriteInt(int x, int y, int intValue, byte direction, byte color);

	std::string ReadString(bool numberChars, bool alphabetChars);

	std::string ReadStringConfig(std::string text, int limit);

	void Font(const wchar_t* fontType, byte fontSizeX, byte fontSizeY, UINT fontFamily, UINT fontWigth);

	void ColorPalette(byte palleteType);

	void ColorPaletteRGB(byte id, byte red, byte green, byte blue);

	void WindowTitle(LPCSTR text);

};

