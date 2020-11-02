#pragma once
#include <filesystem>
namespace load
{
	void Sprite()
	{
		if ((editorState != DRAW_EDITOR_MAIN) && (messageboxBool == true)) {
			menuState = MESSAGEBOX;
			sound.Play(snd::WARNING);
			DrawOKMessageBox(37, 16, LOAD, D_GREY, YELLOW, " ! NOTICE !", "", "You are about to load a sprite!");
			messageboxBool = false;
		}

		countFiles = 0;
		loadSpriteGUI.DrawGUIWindow(48, 44, 0, 0, D_GREY, WHITE);
		loadSpriteGUI.DrawGUILabel(0, 0, " LOAD", true, loadSpriteGUI.color);

		loadSpriteGUI.DrawGUIBox(0, 3, 43, 26, BLACK);

		int fileLoadLoop = 0;
		file = "***NONE***";
		for (auto& p : std::filesystem::directory_iterator("Sprite"))
		{
			if ((p.path().extension() == ".acspr") || (p.path().extension() == ".acxspr"))
			{
				countFiles += 1;
				// Sets the current file to load
				if (fileLoadLoop == fileCusPos) file = p.path().string();

				if ((countFiles > cusOffset) && (countFiles < 25 + cusOffset)) {
					// Cursor
					if (changeCursor == false)
					{
						if (cusPos == 0) loadSpriteGUI.DrawGUILabel(0, fileLoadLoop + 3 - cusOffset, p.path().string(), false, CYAN);
						else loadSpriteGUI.DrawGUILabel(0, fileLoadLoop + 3 - cusOffset, p.path().string(), false, D_CYAN);
						if (fileCusPos == fileLoadLoop) loadSpriteGUI.DrawGUILabel(0, fileLoadLoop + 3 - cusOffset, p.path().string(), false, WHITE);
					}
					else
					{
						if (fileCusPos == fileLoadLoop)
							loadSpriteGUI.DrawGUILabel(0, fileLoadLoop + 3 - cusOffset, p.path().string(), false, GREEN);
						else loadSpriteGUI.DrawGUILabel(0, fileLoadLoop + 3 - cusOffset, p.path().string(), false, D_CYAN);
					}
				}
				fileLoadLoop += 1;
			}
		}
		// Reset cursor position if file explore is changed
		if (fileLoadLoop != countStore)
		{ fileCusPos = 0; cusOffset = 0; }
		countStore = fileLoadLoop;
		loadSpriteGUI.DrawGUILabel(0, 29, " FILE TO LOAD", true, loadSpriteGUI.color);
		loadSpriteGUI.DrawGUILabel(0, 32, file, false, loadSpriteGUI.color);
		loadSpriteGUI.DrawGUIButton(1, 36, "Cancel", cusPos, 1);
		loadSpriteGUI.DrawGUIButton(35, 36, "Load", cusPos, 2);

		// Draw message if file failed to load
		if (fileFailed == true) {
			menuState = MESSAGEBOX;
			sound.Play(snd::FAILED);
			DrawOKMessageBox(44, 16, LOAD, D_RED, BLACK, "FILE INVALID", "", file);

			fileFailed = false;
			file = "";
		}
	}
}