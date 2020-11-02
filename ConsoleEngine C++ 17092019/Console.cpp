#include "EngineCore.h"
#include "Console.h"
#include "Input.h"

#include <conio.h>
#include <thread>

///////////////////////////////////////////////////////////////////////
//							Console	methods							 //
///////////////////////////////////////////////////////////////////////

Console::Console() {};

// FPS timer
using namespace std::literals::chrono_literals;
auto start = std::chrono::high_resolution_clock::now();

// Private - Used to convert integer into a integer array
std::vector <int> Console::integerToArray(int x)
{
	std::vector <int> resultArray;
	while (true)
	{
		resultArray.insert(resultArray.begin(), x % 10);
		x /= 10;
		if (x == 0)
			return resultArray;
	}
}

// Private - Update console window
void Console::UpdateWindowSize(bool GetScreenBufferInfo)
{
	// Update console window
	if (GetScreenBufferInfo == true) GetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);
	csbiInfo.wPopupAttributes = 0;
	csbiInfo.srWindow = { 0, 0, screenWidth, screenHeight };
	csbiInfo.dwSize = { screenWidth, screenHeight };
	csbiInfo.wAttributes = attribute;
	SetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);
}

// Fps get current
void Console::FpsGetCurrent()
{
	// Calculate fps
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	fpsCount = duration.count() - fpsSubtrack;
	fps += 1;

	if (fpsCount >= 1)
	{
		fpsCurrent = fps;
		fpsSubtrack += fpsCount;
		fpsCount = 0;
		fps = 0;
	}
}

// Create console buffer
void Console::Startup()
{
	// Set consolebuffer size and screen dimensions
	SetConsoleActiveScreenBuffer(hConsole);
	m_rectWindow = { 0, 0, screenWidth, screenHeight };

	// Hide console cursor
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo); 

	// Update console window
	UpdateWindowSize(true);
}

// Update screen
void Console::Update()
{
	// Updates screen
	WriteConsoleOutput(hConsole, screen, { screenWidth, screenHeight }, { 0, 0 }, &m_rectWindow);

	// Update console window
	UpdateWindowSize(true);

	// Fps
	FpsGetCurrent();
}

// Draw to point to console buffer
void Console::WriteChar(int x, int y, char character, byte color)
{
	if ((y < screenHeight) && (y >= 0) && (x < screenWidth) && (x >= 0))
	{
		screen[y * screenWidth + x].Attributes = color;
		screen[y * screenWidth + x].Char.AsciiChar = character;
	}
	//Update();
}

// Write string to screen
void Console::WriteString(int x, int y, std::string text, byte direction, byte color)
{
	std::vector<char> charArray(text.begin(), text.end());
	charArray.push_back('\0');
	int xOffset = 0;

	for (int i = 0; i < text.length(); i++)
	{
		switch (charArray[i])
		{
		case '\n'  : y += 1;  xOffset = i + 1; break;		  //Newline
		case '\f'  : color = BLACK;  xOffset += 1; break;	  //Colors
		case '\001': color = D_BLUE;  xOffset += 1; break;	  //Colors
		case '\002': color = D_GREEN;  xOffset += 1; break;	  //Colors
		case '\003': color = D_CYAN;  xOffset += 1; break;	  //Colors
		case '\004': color = D_RED;  xOffset += 1; break;	  //Colors
		case '\005': color = PURPLE;  xOffset += 1; break;	  //Colors
		case '\006': color = D_YELLOW;  xOffset += 1; break;  //Colors
		case '\016': color = L_GREY;  xOffset += 1; break;	  //Colors
		case '\017': color = D_GREY;  xOffset += 1; break;	  //Colors
		case '\020': color = BLUE;  xOffset += 1; break;	  //Colors
		case '\021': color = GREEN; xOffset += 1; break;	  //Colors
		case '\022': color = CYAN; xOffset += 1; break;		  //Colors
		case '\023': color = RED; xOffset += 1; break;		  //Colors
		case '\024': color = MAGENTA; xOffset += 1; break;	  //Colors
		case '\025': color = YELLOW; xOffset += 1; break;	  //Colors
		case '\026': color = WHITE; xOffset += 1; break;	  //Colors
		default:
			if (direction == 0)	WriteChar(x - xOffset + i, y, charArray[i], color); // Write text from left to right
			if (direction == 1)	WriteChar(x - xOffset - i, y, charArray[i], color); // Write text from right to left
			if (direction == 2)	WriteChar(x - xOffset, y + i, charArray[i], color); // Write text from top to button
			if (direction == 3)	WriteChar(x - xOffset, y - i, charArray[i], color); // Write text from button to top
			break;
		}
	}
}

// Write int to screen
void Console::WriteInt(int x, int y, int intValue, byte direction, byte color)
{
	std::vector <int> intArray = integerToArray(intValue);
	int intArrayLength = 0;

	// Gets the size of the int
	for (auto const& intCheckArrayLength : intArray)
		intArrayLength += 1;

	std::vector <char> charArray(intArrayLength);

	for (int i = 0; i < intArrayLength; i++)
	{
		if (intValue > -1) charArray[i] = intArray[i] + 48;
		else
			for (int j = 0, k = 48; (j > -10) && (k < 68); j--, k += 2)
				if (intArray[i] == j)
					charArray[i] = intArray[i] + k;

		if (direction == 0)	WriteChar(x + i, y, charArray[i], color); // Write int from left to right
		if (direction == 1)	WriteChar(x - i, y, charArray[i], color); // Write int from right to left
		if (direction == 2)	WriteChar(x, y + i, charArray[i], color); // Write int from top to button
		if (direction == 3)	WriteChar(x, y - i, charArray[i], color); // Write int from button to top
	}
}

// Read string
std::string Console::ReadString(bool numberChars, bool alphabetChars)
{
	Input input;
	std::string text;

	// Numbers
	if (numberChars == true)
	{
		for (int i = 48; i < 58; i++) {
			if (input.keyStateDelayedLoop(char(i))) text += char(i);
		}
	}

	// Alphabet
	if (alphabetChars == true)
	{
		for (int i = 65; i < 91; i++) {
			if (input.keyStateDelayedLoop(char(i)))
			{
				if (input.keyState(VK_SHIFT)) text += char(i);
				else text += char(i + 32);
			}
		}
		if (input.keyStateDelayedLoop(VK_OEM_MINUS))
		{
			if (input.keyState(VK_SHIFT)) text += '_';
			else text += '-';
		}
	}

	if (input.keyStateDelayedLoop(VK_SPACE)) text += char(32);

	return text;
}

// Read string backspace
std::string Console::ReadStringConfig(std::string text, int limit)
{
	Input input;

	if ((text.length() > limit) && (limit > 0)) text.erase(text.end() - 1);

	if ((input.keyStateDelayedLoop(VK_BACK)) && (text.length() > 0)) text.erase(text.end() - 1);
	return text;
}

// Console set font
void Console::Font(const wchar_t* fontType, byte fontSizeX, byte fontSizeY, UINT fontFamily, UINT fontWeight)
{
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = fontSizeX;
	cfi.dwFontSize.Y = fontSizeY;
	cfi.FontFamily = fontFamily;
	cfi.FontWeight = fontWeight;
	wcscpy_s(cfi.FaceName, fontType);
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void Console::ColorPalette(byte palleteType)
{
	if (palleteType == 0) // Default palette
	{
		colorPlalette[0] = 0x000000;  colorPlalette[1] = 0xAA0000;  colorPlalette[2] = 0x00AA00;  colorPlalette[3] = 0xAAAA00;
		colorPlalette[4] = 0x0000AA;  colorPlalette[5] = 0xAA00AA;  colorPlalette[6] = 0x0055AA;  colorPlalette[7] = 0xAAAAAA;
		colorPlalette[8] = 0x555555;  colorPlalette[9] = 0xFF5555; colorPlalette[10] = 0x55FF55; colorPlalette[11] = 0xFFFF55;
		colorPlalette[12] = 0x5555FF; colorPlalette[13] = 0xFF55FF; colorPlalette[14] = 0x55FFFF; colorPlalette[15] = 0xFFFFFF;
	}

	if (palleteType == 1) // Fancy palette
	{
		colorPlalette[0] = 0x000000;  colorPlalette[1] = 0xFF0000;  colorPlalette[2] = 0x00FF00;  colorPlalette[3] = 0xC0C000;
		colorPlalette[4] = 0x0000FF;  colorPlalette[5] = 0xC000C0;  colorPlalette[6] = 0x0080FF;  colorPlalette[7] = 0xC0C0C0;
		colorPlalette[8] = 0x808080;  colorPlalette[9] = 0xFF8080; colorPlalette[10] = 0x40FF80; colorPlalette[11] = 0xFFFF40;
		colorPlalette[12] = 0x2040FF; colorPlalette[13] = 0xFF80FF; colorPlalette[14] = 0x00FFFF; colorPlalette[15] = 0xFFFFFF;
	}

	csbiInfo.cbSize = sizeof(csbiInfo);
	GetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);

	// Set new color palette
	for (int i = 0; i < 16; i++)
		csbiInfo.ColorTable[i] = colorPlalette[i];

	// Update console window
	UpdateWindowSize(false);
}

// Console set RGB color
void Console::ColorPaletteRGB(byte id, byte red, byte green, byte blue)
{
	csbiInfo.cbSize = sizeof(csbiInfo);
	GetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);

	// Set new color
	csbiInfo.ColorTable[id] = RGB(red, green, blue);

	// Update console window
	UpdateWindowSize(false);
}

// Set top window text
void Console::WindowTitle(LPCSTR text)
{
	SetConsoleTitle(text);
}
