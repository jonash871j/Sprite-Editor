#pragma once
namespace window
{
	// Strings ********************************************************************************************************************************
	std::string spriteMenu01[] = { "Sprite Width", "Sprite Height", "Sprite Name" };
	std::string spriteMenu02[] = { ".acxspr", ".acxani" };
	std::string spriteDesctiption[]
	{
		"\021- Sprite Width\n\03This is used to set the \nsprite width.",
		"\021- Sprite Height\n\03This is used to set the \nsprite height.",
		"\021- Sprite Name\n\03This is used to set the \nsprite name.",
		"\021- acxspr, AsCiieXtraSPRite\n\03.acxspr is an file\nformat that supports 16\ncolors both at the foreground\nand background, and a sprite\nsize up to 4096 chracters.",
		"\021- acxani, AsCiiXtraAnimate\n\03.acxani is an file\nformat that does the\nsame as acxspr, but it also \nallows for multiple sprites \nin the same file.",
		"\021- Cancel\n\03Goes back to main.",
		"\021- Generate\n\03Generates new sprite."
	};

	void NewSprite()
	{
		if ((editorState != DRAW_EDITOR_MAIN) && (messageboxBool == true)) {
			menuState = MESSAGEBOX;
			sound.Play(snd::WARNING);
			DrawOKMessageBox(37, 16, NEW_SPRITE, D_GREY, YELLOW, " ! NOTICE !", "", "You are about to make a new sprite!");
			messageboxBool = false;
		}

		// Generates new window
		newSpriteGUI.DrawGUIWindow(34, 36, 0, 0, D_GREY, WHITE);

		// New sprite section *****************************************************************************************************************
		newSpriteGUI.DrawGUILabel(0, 0, " NEW SPRITE", true, newSpriteGUI.color);
		newSpriteGUI.DrawGUIMenu(0, 3, spriteMenu01, 3, newSpriteCusPos, 0);

		// Draws a seperator betwheen the textboxes, and labels
		for (int i = 0; i < 3; i++)
			newSpriteGUI.DrawGUIChar(14, 3 + i, ':', newSpriteGUI.color);

		// Textboxes 
		newSpriteGUI.DrawGUIBox(15, 3, 28, 5, 0);
		spriteGuiWidth = newSpriteGUI.DrawGUITextBoxInt(15, 3, 4, maxSpriteSize, spriteGuiWidth, WHITE, GREEN, newSpriteCusPos, 0);
		spriteGuiHeight = newSpriteGUI.DrawGUITextBoxInt(15, 4, 4, maxSpriteSize, spriteGuiHeight, WHITE, GREEN, newSpriteCusPos, 1);
		spriteGuiName = newSpriteGUI.DrawGUITextBoxString(15, 5, 255, spriteGuiName, WHITE, GREEN, newSpriteCusPos, 2);

		// File format section ****************************************************************************************************************
		newSpriteGUI.DrawGUILabel(0, 9, " FILE FORMAT", true, newSpriteGUI.color);

		// Checkbox
		newSpriteGUI.DrawGUICheckBoxMenu(0, 12, 8, spriteMenu02, 2, newSpriteCusPos, 3, newSpriteCheckBoxState);
		switch (newSpriteCheckBoxState) {
		case NEW_SPRITE_CHECKBOX_ACXSPR: maxSpriteSize = 4096; break;
		case NEW_SPRITE_CHECKBOX_ACSPR: maxSpriteSize = 40; break;
		}

		// Description section ****************************************************************************************************************
		newSpriteGUI.DrawGUILabel(0, 15, " DESCRIPTION", true, newSpriteGUI.color);
		newSpriteGUI.DrawGUIBox(0, 18, 28, 23, 0);
		newSpriteGUI.DrawGUILabel(0, 18, spriteDesctiption[newSpriteCusPos], false, WHITE);

		// Buttons ****************************************************************************************************************************
		newSpriteGUI.DrawGUIButton(1, 28, "Cancel", newSpriteCusPos, 5);
		newSpriteGUI.DrawGUIButton(16, 28, "Generate", newSpriteCusPos, 6);
	}
}