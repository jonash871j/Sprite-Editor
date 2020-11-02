#pragma once
#include "EditorFunctions.h"
#include "EditorInputMainBar.h"
#include "EditorInputToolBar.h"
#include "EditorInputNewSpriteGUI.h"
#include "EditorInputLoadSpriteGUI.h"
#include "EditorInputShowPaletteGUI.h"
#include "EditorInputSpriteEditorColorbar.h"
#include "EditorInputSpriteEditorCharacterbar.h"
#include "EditorInputSpriteEditorWorkspace.h"
#include "EditorInputSpriteEditorPreview.h"

bool editorSpriteToolbar = false;

void InputEvents()
{
	// Leave menu input
	if (input.keyPressed(VK_ESCAPE))
	{
		if (load::changeCursor == false) menuState = MAINBAR;
		else load::changeCursor = false;
		sound.Play(snd::CLICK);
	}
	if (menuState == TOOL_MENU) editorSpriteToolbar = true;
	if (menuState == MAINBAR) editorSpriteToolbar = false;

	// Input for sprite editor preview
	if (editorState == DRAW_EDITOR_SPRITE_PREVIEW)
		editspr::PreviewInput();

	if ((editorState == DRAW_EDITOR_SPRITE) && (editorSpriteToolbar == false))
	{
		// Enable preview window
		if (input.keyPressed(VK_F5)) {
			editspr::workspaceState = false;
			editorSpriteMenu = EDITOR_CYCLE_SPRITE_MAINBAR;
			editorState = DRAW_EDITOR_SPRITE_PREVIEW;
			editspr::SaveACXSPR("%%%");
			editspr::sprite.ImportSprite("./sprite/%%%");
			remove("./sprite/%%%.acxspr");

			editspr::xPrePos = 0;
			editspr::yPrePos = 0;
		}

		if (editorSpriteMenu != EDITOR_CYCLE_SPRITE_WORKSPACE){
			if (input.keyPressed(VK_DOWN)) editorSpriteMenu += 1;
			if (input.keyPressed(VK_UP)) editorSpriteMenu -= 1;
		}
		// Grid toggle
		if (input.keyPressed('G')){ switch (editspr::gridState) {
		case true: editspr::gridState = false; break;
		case false: editspr::gridState = true; break;
		}	}

		// Switch between workspace and toobar
	    else if (input.keyPressed(VK_CONTROL)){
			switch (editspr::workspaceState) {
			case false: 
				editspr::workspaceState = true;
				menuState =        EDITOR_SPRITE_WORKSPACE; 
				editorSpriteMenu = EDITOR_CYCLE_SPRITE_WORKSPACE;
				break;
			case true: 
				editspr::workspaceState = false;
				menuState =        MAINBAR;
				editorSpriteMenu = EDITOR_CYCLE_SPRITE_MAINBAR;
				break;
			}
		}
		if (editorSpriteMenu < EDITOR_CYCLE_SPRITE_MAINBAR) 
			editorSpriteMenu = EDITOR_CYCLE_SPRITE_CHRACTERBAR;

		if ((editorSpriteMenu > EDITOR_CYCLE_SPRITE_CHRACTERBAR) && (editspr::workspaceState == false))
			editorSpriteMenu = EDITOR_CYCLE_SPRITE_MAINBAR;

		switch (editorSpriteMenu) {
		case EDITOR_CYCLE_SPRITE_MAINBAR:     menuState = MAINBAR; break;
		case EDITOR_CYCLE_SPRITE_COLORBAR:    menuState = EDITOR_SPRITE_COLORBAR;      break;
		case EDITOR_CYCLE_SPRITE_CHRACTERBAR: menuState = EDITOR_SPRITE_CHRACTERBAR;   break;
		}
	}

	switch (menuState)
	{
	case MAINBAR                  : MainBarEvents();			   break;
	case TOOL_MENU                : ToolBarEvents();			   break;
	case NEW_SPRITE               : NewSpriteGUIEvents();		   break;
	case LOAD                     : load::SpriteGUIEvents();	   break;
	case SHOW_PALETTE             : ShowPaletteGUIEvents();		   break;
	case EDITOR_SPRITE_COLORBAR   : editspr::ColorbarEvents();     break;
	case EDITOR_SPRITE_CHRACTERBAR: editspr::CharacterbarEvents(); break;
	case EDITOR_SPRITE_WORKSPACE  : editspr::WorkspaceEvents();    break;
	}
	updateScreen = true;
}

