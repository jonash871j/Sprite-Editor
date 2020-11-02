#pragma once
#include "FileACXSPR.h"
#include "FileACSPR.h"

void ToolBarEvents()
{
	// Toolbar controls
	if (input.keyPressed(VK_DOWN)) toolBarCusPos += 1;
	if (input.keyPressed(VK_UP)) toolBarCusPos -= 1;

	// Toolbar enter events 
	if (input.keyPressed(VK_RETURN))
	{
		messageboxBool = true;
		sound.Play(snd::CLICK);
		if (mainBarCusPos == MAINBAR_FILE)
		{
			//************************************//MENU_FILE EVENTS//************************************//
			switch (toolBarCusPos)
			{
			case TOOL_MENU_NEW_SPRITE:
				newSpriteCusPos = NEW_SPRITE_MENU_SPRITE_WIDTH;
				spriteGuiWidth = 16;
				spriteGuiHeight = 16;
				spriteGuiName = "newsprite";
				newSpriteCheckBoxState = NEW_SPRITE_CHECKBOX_ACXSPR;
				menuState = NEW_SPRITE;
				break;
			case TOOL_MENU_NEW_MAP:
				menuState = NEW_MAP;
				break;
			case TOOL_MENU_LOAD:
				load::cusPos = 0;
				load::fileCusPos = 0;
				load::cusOffset = 0;
				load::fileCusPos = LOAD_FILEMENU;
				menuState = LOAD;
				break;
			case TOOL_MENU_SAVE:
				editspr::SaveACXSPR(editspr::name);
				menuState = SAVE;
				break;
			case TOOL_MENU_SAVE_AS:
				menuState = SAVE_AS;
				break;
			}
		}
		//************************************//MENU_COLOR_PALETTE EVENTS//************************************//
		if (mainBarCusPos == MAINBAR_COLOR_PALETTE)
		{
			switch (toolBarCusPos)
			{
			case TOOL_MENU_SHOW_PALETTE:
				menuState = SHOW_PALETTE;
				break;
			case TOOL_MENU_LOAD_PALETTE:
				break;
			case TOOL_MENU_NEW_PALETTE:
				break;
			}
		}
		//************************************//MENU_CONFIG EVENTS//************************************//}
	}
}