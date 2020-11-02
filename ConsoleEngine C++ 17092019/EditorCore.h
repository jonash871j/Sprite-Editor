#pragma once

// Define editor states
#define DRAW_EDITOR_MAIN 0
#define DRAW_EDITOR_SPRITE 1
#define DRAW_EDITOR_SPRITE_PREVIEW 2

// Define sprite editor cycles
#define EDITOR_CYCLE_SPRITE_MAINBAR 0
#define EDITOR_CYCLE_SPRITE_COLORBAR 1
#define EDITOR_CYCLE_SPRITE_CHRACTERBAR 2
#define EDITOR_CYCLE_SPRITE_WORKSPACE 3

// Menu state definitions
#define MAINBAR 0
#define MESSAGEBOX 1
#define TOOL_MENU 2
#define NEW_SPRITE 3
#define NEW_MAP 4
#define LOAD 5
#define SAVE 6
#define SAVE_AS 7
#define SHOW_PALETTE 8
#define LOAD_PALETTE 9
#define NEW_PALETTE 10
#define EDITOR_SPRITE_COLORBAR 11
#define EDITOR_SPRITE_CHRACTERBAR 12
#define EDITOR_SPRITE_WORKSPACE 13

// Main bar event definitions
#define MAINBAR_FILE 0
#define MAINBAR_COLOR_PALETTE 1
#define MAINBAR_CONFIG 2
#define MAINBAR_EXIT 3

// Tool bar file event definitions
#define TOOL_MENU_NEW_SPRITE 0
#define TOOL_MENU_NEW_MAP 1
#define TOOL_MENU_LOAD 2
#define TOOL_MENU_SAVE 3
#define TOOL_MENU_SAVE_AS 4

// Tool bar color palette event definitions
#define TOOL_MENU_SHOW_PALETTE 0
#define TOOL_MENU_LOAD_PALETTE 1
#define TOOL_MENU_NEW_PALETTE 2

// NewSprite menu
#define NEW_SPRITE_MENU_SPRITE_WIDTH 0
#define NEW_SPRITE_MENU_SPRITE_HEIGHT 1
#define NEW_SPRITE_MENU_SPRITE_NAME 2
#define NEW_SPRITE_MENU_SPRITE_ACXSPR 3
#define NEW_SPRITE_MENU_SPRITE_ACSPR 4
#define NEW_SPRITE_MENU_CANCEL 5
#define NEW_SPRITE_MENU_GENERATE 6

// Load menu
#define LOAD_FILEMENU 0
#define LOAD_CANCEL 1
#define LOAD_LOAD 2

// NewSprite checkboxes
#define NEW_SPRITE_CHECKBOX_ACXSPR 0
#define NEW_SPRITE_CHECKBOX_ACSPR 1

// Sound
namespace snd
{
	using namespace std;
	static const char* CLICK = "data/sound/Click.wav";
	static const char* CLICK_FORWARD = "data/sound/ClickForward.wav";
	static const char* CLICK_BACKWARD = "data/sound/ClickBackward.wav";
	static const char* CHECKBOX = "data/sound/Checkbox.wav";
	static const char* FAILED = "data/sound/Error.wav";
	static const char* WARNING = "data/sound/Warning.wav";
}

enum asciiCharacters
{
	LW_RTCOR2X = 188,
	UP_RTCOR2X = 187,
	UP_LFCOR2X = 201,
	LW_LFCOR2X = 200,
	VER_LINE2X = 186,
	HOR_LINE2X = 205,
	LW_RTCOR1X = 217,
	UP_RTCOR1X = 191,
	UP_LFCOR1X = 218,
	LW_LFCOR1X = 192,
	VER_LINE1X = 179,
	HOR_LINE1X = 196,
	BLOCKHALFU = 223,
	BLOCKHALFD = 220,
	BLOCKFULL = 219,
	BLOCK75P = 178,
	BLOCK50P = 177,
	BLOCK25P = 176,
	LF_ARROW = 17,
	RT_ARROW = 16,
	DOT = 7,
};