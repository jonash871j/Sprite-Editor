#include "EditorDraw.h"
#include <iostream>

//std::string test;


int main()
{
	console.Startup();
	console.Font(L"Terminal", 16, 16, FF_DONTCARE, FW_NORMAL);
	console.ColorPalette(DEFAULT_COLOR_PALETTE);
	button_ok.ImportSprite("./data/sprite/spr_engineButton");
	editspr::colorCus.ImportSprite("./data/sprite/spr_engineCursor");
	editspr::colorCus.ImportSprite("./data/sprite/spr_engineCursorSelected");

	while (exitState == false)
	{
		// Draws background
		draw.Background(backgroundTexture, backgroundColor);

		// Draws welcome message
		if (startupState == true) menuState = MESSAGEBOX;
		DrawOKMessageBox(32, 16, MAINBAR, D_BLUE, WHITE, "Welcome to Engine Editor", "", " v1.1 Alpha");

		//Input for mainbar 
		InputEvents();

		// Check if is key pressed
		if (input.keyState(VK_SPACE)) NULL;
		if (input.keyState('Z')) NULL;
		if (input.keyState(VK_MENU)) NULL;

		// Draw main
		Draw();

		console.Update();
		Sleep(10);

		startupState = false;
		updateScreen = false;
	}
}

