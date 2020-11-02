#pragma once
#include "EditorDrawSpritePreview.h"

namespace editspr
{
	byte fbColor = 31;
	byte fbBackground = 1;


	void DrawEditor()
	{
		// Draws mainbar at the top
		drawMainBar(2);

		// Draw color bar
		draw.Rectangle(0, 1, screenWidth, 4, BLOCK50P, D_GREY, false);
		for (int i = 0; i < 16; i++) {
			draw.Rectangle((3 * i) + 2, 2, (3 * i) + 1, 3, 219, i, false);
			draw.Rectangle((3 * -i) + screenWidth - 2, 2, (3 * -i) + screenWidth - 3, 3, 219, i, false);
			// Draw selected cursor
			if (i == colorForegrund) colorCusSelected.SpriteDraw((3 * i), 1);
			if (i == colorBackground) colorCusSelected.SpriteDraw((3 * -i) + screenWidth - 4, 1);
		}
		//draw.Rectangle((3 * -i) + screenWidth - 2, 2, (3 * -i) + screenWidth - 3, 3, 219, i, false);
		// Draw cursor
		for (int i = 0; i < 16; i++) {
			if (menuState == EDITOR_SPRITE_COLORBAR)
			{
				if ((i == colorBarCusPos) && (colorBarCusPos < 16)) colorCus.SpriteDraw((3 * i), 1);
				if ((i == colorBarCusPos - 16) && (colorBarCusPos > 15)) colorCus.SpriteDraw((3 * i) + xMid + 11, 1);
			}
		}

		// ColorBarCusPos reset
		if (colorBarCusPos >= 32) colorBarCusPos = 0;
		if (colorBarCusPos < 0) colorBarCusPos = 31;

		// Draw color sample
		draw.Rectangle(xMid - 11, 1, xMid + 10, 4, 0, BLACK, false);
		draw.Rectangle(xMid - 9, 2, xMid - 9, 3, BLOCKFULL, colorForegrund, false);
		draw.Rectangle(xMid - 7, 2, xMid - 7, 3, BLOCK75P, (colorBackground * 16) + colorForegrund, false);
		draw.Rectangle(xMid - 5, 2, xMid - 5, 3, BLOCK50P, (colorBackground * 16) + colorForegrund, false);
		draw.Rectangle(xMid - 3, 2, xMid - 3, 3, BLOCK25P, (colorBackground * 16) + colorForegrund, false);
		draw.Rectangle(xMid + 2, 2, xMid + 2, 3, BLOCK25P, (colorForegrund * 16) + colorBackground, false);
		draw.Rectangle(xMid + 4, 2, xMid + 4, 3, BLOCK50P, (colorForegrund * 16) + colorBackground, false);
		draw.Rectangle(xMid + 6, 2, xMid + 6, 3, BLOCK75P, (colorForegrund * 16) + colorBackground, false);
		draw.Rectangle(xMid + 8, 2, xMid + 8, 3, ' ', (colorBackground * 16) + colorForegrund, false);

		// Draws character with color sample
		draw.Rectangle(xMid - 1, 2, xMid, 3, charCusPos + charBarPos, (colorBackground * 16) + colorForegrund, false);

		// Characterbar ***********************************************************************************************************************************************
		draw.Rectangle(0, 5, screenWidth, 6, BLOCKFULL, D_GREY, false);
		draw.Rectangle(0, 6, screenWidth, 6, '_', 143, false);

		for (int i = 0; i < 255; i++)
		{
			if (i == charCusPos)
			{
				// Sets the color of cursorpostion 
				int colorChar;
				if (menuState == EDITOR_SPRITE_CHRACTERBAR) colorChar = 46; else colorChar = 130;

				console.WriteChar(i + i, 5, i + charBarPos, colorChar);
			}
			else console.WriteChar(i + i, 5, i + charBarPos, 143);
		}

		// Characterbar limit 
		if (charCusPos + charBarPos < 0)
		{
			charCusPos = (screenWidth / 2) - 1;
			charBarPos = 256 - (screenWidth / 2);
		}
		if (charCusPos + charBarPos > 255)
		{
			charCusPos = 0;
			charBarPos = 0;
		}

		// Checking if spriteheight or spritewidth is a odd number
		// Then offsetes it by one
		if (width - width == width % 2) xOffset = 0;
		else xOffset = 1;
		if (height - height == height % 2) yOffset = 0;
		else yOffset = 1;

		// Draw workspace *********************************************************************************************************************************************
		SpriteWorkspaceGUI.DrawGUIWindow(width + 4, height + 4, 0, 0, BLACK, D_BLUE);
		SpriteWorkspaceGUI.DrawGUILabel(-2 - xOffset, -2 - yOffset, "DRAW", false, WHITE);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (gridState == true)
					SpriteWorkspaceGUI.DrawGUIChar(x - xOffset, y - yOffset, 254, C(D_GREY, BLACK));
				if (arrayCharacter[y][x] != char(0))
					SpriteWorkspaceGUI.DrawGUIChar(x - xOffset, y - yOffset, arrayCharacter[y][x], arrayColor[y][x]);
			}
		}

		// Workspace cursor
		SpriteWorkspaceGUI.DrawGUIChar(xPos - xOffset, yPos - yOffset, 254, 240);

		// Draw infomation GUI
		SpriteInfomationGUI.DrawGUIWindow(18, 40, (screenWidth / 2) - 14, 0, D_BLUE, YELLOW);
		SpriteInfomationGUI.DrawGUILabel(0, 0, " INFOMATION", true, SpriteInfomationGUI.color);

		// Show character infmation for cell
		switch (arrayCharacter[yPos][xPos])
		{
			case char(0) : charInfo = "NULL"; charColorInfo = 29; break;
				case char(32) : charInfo = "SPACE"; charColorInfo = 29; break;
					case char(255) : charInfo = "NBSP"; charColorInfo = 29; break;
					default: charInfo = arrayCharacter[yPos][xPos]; charColorInfo = SpriteInfomationGUI.color; break;
		}
		SpriteInfomationGUI.DrawGUILabel(0, 3, "Character: ", false, SpriteInfomationGUI.color);
		SpriteInfomationGUI.DrawGUIChar(11, 3, arrayCharacter[yPos][xPos], charColorInfo);
		SpriteInfomationGUI.DrawGUILabel(11, 3, charInfo, false, charColorInfo);
		SpriteInfomationGUI.DrawGUILabel(0, 4, "Color    : ", false, SpriteInfomationGUI.color);
		SpriteInfomationGUI.DrawGUIChar(11, 4, 254, arrayColor[yPos][xPos]);

		SpriteInfomationGUI.DrawGUILabel(0, 6, "Width    : ", false, SpriteInfomationGUI.color);
		SpriteInfomationGUI.DrawGUINumber(11, 6, width, SpriteInfomationGUI.color);
		SpriteInfomationGUI.DrawGUILabel(0, 7, "Height   : ", false, SpriteInfomationGUI.color);
		SpriteInfomationGUI.DrawGUINumber(11, 7, height, SpriteInfomationGUI.color);

		fileSize = (width * height) * 2;
		if (fileSize <= 1024) { fileSizePrefix = "BYTES"; }
		else if (fileSize <= 1048576) { fileSizePrefix = "KB"; fileSize = fileSize / 1024; }
		else if (fileSize <= 1073741824) { fileSizePrefix = "MB"; fileSize = (fileSize / 1024) / 1024; }

		SpriteInfomationGUI.DrawGUINumber(0, 9, fileSize, 31);
		SpriteInfomationGUI.DrawGUILabel(4, 9, fileSizePrefix, false, 31);

		if (name.length() > 15)
		{
			nameCutOff = name;
			nameCutOff.erase(13, name.length());
			nameCutOff += "...";
			SpriteInfomationGUI.DrawGUILabel(0, 10, nameCutOff, false, 31);
		}
		else SpriteInfomationGUI.DrawGUILabel(0, 10, name, false, 31);

		// Draws sprite editor infomation footer **********************************************************************************************************************
		draw.Rectangle(0, screenHeight - 2, screenWidth, screenHeight - 2, 219, fbBackground, false);
		console.WriteString(1, screenHeight - 2, "X: ", 0, fbColor);
		console.WriteInt(4, screenHeight - 2, xPos, 0, fbColor);
		console.WriteString(8, screenHeight - 2, "Y: ", 0, fbColor);
		console.WriteInt(11, screenHeight - 2, yPos, 0, fbColor);
		console.WriteChar(16, screenHeight - 2, VER_LINE1X, fbColor);

		console.WriteString(21, screenHeight - 2, "Color Foreground: |", 0, fbColor);
		console.WriteChar(38, screenHeight - 2, 254, 240 + colorForegrund);
		console.WriteInt(40, screenHeight - 2, colorForegrund, 0, fbColor);
		console.WriteString(44, screenHeight - 2, "Color Background: |", 0, fbColor);
		console.WriteChar(61, screenHeight - 2, 254, 240 + colorBackground);
		console.WriteInt(63, screenHeight - 2, colorBackground, 0, fbColor);
		console.WriteChar(68, screenHeight - 2, VER_LINE1X, fbColor);

		console.WriteString(73, screenHeight - 2, "Character: |", 0, fbColor);
		console.WriteChar(83, screenHeight - 2, charCusPos + charBarPos, fbColor);;
		console.WriteInt(85, screenHeight - 2, charCusPos + charBarPos, 0, fbColor);

		// Draws array footer
		switch (menuState)
		{
		case EDITOR_SPRITE_COLORBAR:
			drawFooter(fbColorbar, 3, 3);
			break;
		case EDITOR_SPRITE_CHRACTERBAR:
			drawFooter(fbCharbar, 3, 2);
			break;
		case EDITOR_SPRITE_WORKSPACE:
			drawFooter(fbWorkspace, 3, 5);
			break;
		default:
			drawFooter(editspr::fbMain, 3, 5);
			break;
		}

		// Changes background
		backgroundColor = D_GREY;
		backgroundTexture = 176;
	}
}