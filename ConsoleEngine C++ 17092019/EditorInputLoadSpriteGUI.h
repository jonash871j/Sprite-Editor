#pragma once
namespace load
{
	void SpriteGUIEvents()
	{
		// Menu navigation input
		if (changeCursor == false)
		{
			if ((input.keyPressed(VK_UP)) && (cusPos > 0))
			{
				cusPos -= 1; if (cusPos >= 1) cusPos = 0;
			} // Also used to get out of buttons menu
			if ((input.keyPressed(VK_DOWN)) && (cusPos < 1)) cusPos += 1;
			if ((input.keyPressed(VK_RIGHT)) && (cusPos == 1)) cusPos += 1;
			if ((input.keyPressed(VK_LEFT)) && (cusPos == 2)) cusPos -= 1;
		}
		else
		{
			if ((input.keyPressed(VK_UP)) && (fileCusPos > 0))
			{
				fileCusPos -= 1;
				if (fileCusPos >= 23) cusOffset -= 1;
			}
			if ((input.keyPressed(VK_DOWN)) && (fileCusPos < countFiles - 1))
			{
				fileCusPos += 1;
				if (fileCusPos > 23) cusOffset += 1;
			}
		}
		// New sprite enter events 
		if (input.keyPressed(VK_RETURN))
		{
			switch (cusPos)
			{
			case LOAD_FILEMENU:
				sound.Play(snd::CLICK);
				switch (changeCursor) {
				case true: changeCursor = false; break;
				case false: changeCursor = true; break;
				}
				break;
			case LOAD_CANCEL:
				sound.Play(snd::CLICK);
				menuState = MAINBAR;
				break;
			case LOAD_LOAD:
				sound.Play(snd::CLICK);

				// Load files
				if (editspr::LoadACXSPR() == true)
				{
					file.erase(0, 7);
					file.erase(file.length() - 7, -7);
				}
				else if (editspr::LoadACSPR() == true)
				{
					file.erase(0, 7);
					file.erase(file.length() - 6, -6);
				}
				else
				{ 
					fileFailed = true; 
					break; 
				}
				// Resets cursor coordinates in sprite editor
				editspr::xPos = 0; 
				editspr::yPos = 0;

				editspr::name = file;
				editorState = DRAW_EDITOR_SPRITE;
				menuState = MAINBAR;
				break;
			}
		}

	}
}