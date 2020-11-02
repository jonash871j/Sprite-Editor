#pragma once
#include "Engine.h"
#include "EditorCore.h"
#include "EditorCreateGUI.h"
#include "EditorMainGui.h"

// Startup
bool startupState = true;
bool updateScreen = true;

// General
byte backgroundColor = 1;
byte backgroundTexture = 176;
bool messageboxBool = false;

// Exit
bool exitState = false;

// Editors ***************************************************************************************************
int editorState = DRAW_EDITOR_MAIN;
int editorSpriteMenu = 0;

// Sprite editor ********************************************************************************************
namespace editspr
{
	// Footers
	std::string fbMain[] = { "use CTRL to cycle mode", "press ENTER to select", "press ESC to go back", "use ARROW-KEYS for cursor", "use F5 to preview" };
	std::string fbWorkspace[] = { "use CTRL to cycle mode", "use SPACE to draw", "use DEL to erase", "use Z to fill ASCII", "use ALT to fill \023CO\025LO\021RS" };
	std::string fbColorbar[] = { "use CTRL to cycle mode", "press ENTER to select", "use ARROW-KEYS for cursor" };
	std::string fbCharbar[] = { "use CTRL to cycle mode", "use ARROW-KEYS for cursor" };
	std::string fbPreview[] = { "use F5 to stop preview", "use NUMBERS to scale", "use ARROW-KEYS to move sprite" };

	// Workspace
	std::string name = "newsprite";
	char** arrayCharacter;
	char** arrayColor;
	bool gridState = true;
	bool workspaceState = false;
	int xOffset, yOffset;
	int width, height;
	int xPos = 0;
	int yPos = 0;

	// Colorbar
	Object colorCus;
	Object colorCusSelected;
	byte colorBackground = 0;
	byte colorForegrund = 15;
	byte charColorInfo = 0;
	int colorBarCusPos = 0;

	// Characterbar
	int charCusPos = 0;
	int charBarPos = 0;
	int charCurrentPallete = 0;
	std::string charInfo = "";

	// Infomationbar
	int fileSize;
	std::string fileSizePrefix;
	std::string nameCutOff;

	// Preview
	Object sprite;
	int xPrePos = 0;
	int yPrePos = 0;
}

// Menus *****************************************************************************************************
int menuState = MAINBAR;
bool textBoxMode = false;

// Mainbar
int mainBarCusPos = MAINBAR_FILE;
int characterLength;
std::string mainBar[] = { "File", "Color Palette", "Config", "Exit" };

// Toolbar
int toolBarCusPos = 0;

// Filemenu
std::string fileMenu01[] = { "New Sprite", "New Map", "Load" };
std::string fileMenu02[] = { "Save", "Save As" };
std::string fileMenu03[] = { "Change sprite", "Convert sprite", };

// Colormenu
std::string colpalMenu01[] = { "Show Palette" };
std::string colpalMenu02[] = { "Load Palette", "New Palette" };

// Configmenu
std::string configMenu01[] = { "General" };

int newSpriteCusPos = NEW_SPRITE_MENU_SPRITE_WIDTH;
int newSpriteCheckBoxState = NEW_SPRITE_CHECKBOX_ACXSPR;
int spriteGuiWidth = 16;
int spriteGuiHeight = 16;
std::string spriteGuiName = "";
int maxSpriteSize = 4096;

// Load menu
namespace load
{
	std::string file = "";
	int countFiles;
	int countStore;
	int cusPos = LOAD_FILEMENU;
	int cusOffset = 0;
	int fileCusPos = 0;
	bool changeCursor = 0;
	bool fileFailed = false;
}

// Color palette menu
int colPalCusPos = 0;

// Footer
std::string footerBarMain[] = { "press ENTER to select", "press ESC to go back", "use ARROW-KEYS for cursor" };

int footerBarLenght;

// MainGui
EditorMainGUI mainGUI;

// Create GUI
EditorCreateGui newSpriteGUI;
EditorCreateGui loadSpriteGUI;
EditorCreateGui showPaletteGUI;
EditorCreateGui SpriteWorkspaceGUI;
EditorCreateGui SpriteInfomationGUI;