#pragma once
#include <Windows.h>
#include <string>

#define BLACK 0
#define D_BLUE 1
#define D_GREEN 2
#define D_CYAN 3
#define D_RED 4
#define PURPLE 5
#define D_YELLOW 6
#define L_GREY 7
#define D_GREY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

#define DEFAULT_COLOR_PALETTE 0
#define FANCY_COLOR_PALETTE 1

#define LEFT_TO_RIGHT 0
#define RIGHT_TO_LEFT 1
#define TOP_TO_BUTTOM 2
#define BUTTOM_TO_TOP 3

#define NONE 0

const int screenWidth = 120;
const int screenHeight = 67;

const int xMid = screenWidth / 2;
const int yMid = screenHeight / 2;

static CONSOLE_SCREEN_BUFFER_INFOEX csbiInfo;
static CONSOLE_CURSOR_INFO cursorInfo;
static CONSOLE_FONT_INFOEX cfi;
static SMALL_RECT m_rectWindow;
static CHAR_INFO* screen = new CHAR_INFO[screenWidth * screenHeight];

static HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
static WORD attribute;

static int C(int foreground, int background)
{
	return (background * 16) + foreground;
}
