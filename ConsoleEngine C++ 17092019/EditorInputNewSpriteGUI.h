#pragma once

void NewSpriteGUIEvents()
{
	if (newSpriteGUI.textBoxMode == false)
	{
		// Menu navigation input
		if ((input.keyPressed(VK_UP)) && (newSpriteCusPos > 0))
		{
			newSpriteCusPos -= 1; if (newSpriteCusPos >= 5) newSpriteCusPos = 4;
		} // Also used to get out of buttons menu

		if ((input.keyPressed(VK_DOWN)) && (newSpriteCusPos < 5)) newSpriteCusPos += 1;
		if ((input.keyPressed(VK_RIGHT)) && (newSpriteCusPos == 5)) newSpriteCusPos += 1;
		if ((input.keyPressed(VK_LEFT)) && (newSpriteCusPos == 6)) newSpriteCusPos -= 1;

		// New sprite enter events 
		if (input.keyPressed(VK_RETURN))
		{
			switch (newSpriteCusPos)
			{
			case NEW_SPRITE_MENU_SPRITE_WIDTH:
				sound.Play(snd::CLICK);
				newSpriteGUI.stringNumber = std::to_string(spriteGuiWidth);
				newSpriteGUI.textBoxMode = true;
				break;
			case NEW_SPRITE_MENU_SPRITE_HEIGHT:
				sound.Play(snd::CLICK);
				newSpriteGUI.stringNumber = std::to_string(spriteGuiHeight);
				newSpriteGUI.textBoxMode = true;
				break;
			case NEW_SPRITE_MENU_SPRITE_NAME:
				sound.Play(snd::CLICK);
				newSpriteGUI.textBoxMode = true;
				break;
			case NEW_SPRITE_MENU_SPRITE_ACXSPR:
				sound.Play(snd::CHECKBOX);
				newSpriteCheckBoxState = NEW_SPRITE_CHECKBOX_ACXSPR;
				break;
			case NEW_SPRITE_MENU_SPRITE_ACSPR:
				sound.Play(snd::CHECKBOX);
				newSpriteCheckBoxState = NEW_SPRITE_CHECKBOX_ACSPR;
				break;
			case NEW_SPRITE_MENU_CANCEL:
				sound.Play(snd::CLICK);
				menuState = MAINBAR;
				break;
			case NEW_SPRITE_MENU_GENERATE:
				sound.Play(snd::CLICK);

				// Deletes old array
				editspr::Delete();

				// Set new sprite size
				editspr::width = spriteGuiWidth;
				editspr::height = spriteGuiHeight;

				// Resets cursor coordinates in sprite editor
				editspr::xPos = 0;
				editspr::yPos = 0;

				// Sets the name of sprite
				editspr::name = spriteGuiName;

				// Defines the size of the arrays
				editspr::NewArrays();

				editorState = DRAW_EDITOR_SPRITE;
				menuState = MAINBAR;
				break;
			}
		}
	}
}