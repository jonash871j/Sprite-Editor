#pragma once
#include "EditorInput.h"
#include "EditorDrawSpriteEditor.h"
#include "EditorDrawNewSprite.h"
#include "EditorDrawLoadSprite.h"
#include "EditorDrawShowPalette.h"

ToolMenu toolMenuFile;
ToolMenu toolMenuColPal;
ToolMenu toolMenuConfig;

void Draw()
{
	switch (editorState)
	{
	case DRAW_EDITOR_SPRITE:
		editspr::DrawEditor();
		break;
	case DRAW_EDITOR_SPRITE_PREVIEW:
		editspr::Preview();
		break;
	default:
		// Draws mainbar at the top
		drawMainBar(2);
		// Draws footer
		drawFooter(footerBarMain, 3, 3);
		break;
	}

	switch (mainBarCusPos) {
		//************************************//MENU_FILE GUI DRAW EVENTS//************************************//
	case MAINBAR_FILE:
		// Draws tool menu
		toolMenuFile.DrawMenu(14, 0, 1, D_CYAN, BLACK);
		toolMenuFile.AddMenu(fileMenu01, 3);
		if (editorState == DRAW_EDITOR_SPRITE)
			toolMenuFile.AddMenu(fileMenu02, 2);
		toolMenuFile.stopMenu();

		// Draws GUIS
		switch (menuState)
		{
		case NEW_SPRITE:
			menuState = NEW_SPRITE;
			window::NewSprite();
			break;
		case NEW_MAP:
			menuState = MESSAGEBOX;
			DrawOKMessageBox(32, 16, MAINBAR, WHITE, D_CYAN, "TOOL_MENU_NEW_MAP", "OK", "OK");
			break;
		case LOAD:
			menuState = LOAD;
			load::Sprite();
			break;
		case SAVE:
			menuState = MESSAGEBOX;
			DrawOKMessageBox(32, 16, MAINBAR, D_CYAN, YELLOW, "Sprite Saved", editspr::name + ".acxspr", "");
			break;
		case SAVE_AS:
			menuState = MESSAGEBOX;
			DrawOKMessageBox(32, 16, MAINBAR, WHITE, D_CYAN, "SAVE_AS", "OK", "OK");
			break;
		default: break;
		}
		break;
	case MAINBAR_COLOR_PALETTE:
		// Draws tool menu
		toolMenuColPal.DrawMenu(14, 6, 1, D_CYAN, BLACK);
		toolMenuColPal.AddMenu(colpalMenu01, 1);
		toolMenuColPal.AddMenu(colpalMenu02, 2);
		toolMenuColPal.stopMenu();

		// Draws GUIS
		switch (menuState)
		{
		case SHOW_PALETTE:
			menuState = SHOW_PALETTE;
			ShowPalette();
			break;
		}
		break;
	case MAINBAR_CONFIG:
		// Draws tool menu
		toolMenuConfig.DrawMenu(14, 21, 1, D_CYAN, BLACK);
		toolMenuConfig.AddMenu(configMenu01, 1);
		toolMenuConfig.stopMenu();
		break;
	}
}
