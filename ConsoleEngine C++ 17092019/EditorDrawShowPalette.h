#pragma once

void ShowPalette()
{
	// Limits
	if (colPalCusPos < 0) colPalCusPos = 15;
	if (colPalCusPos > 15) colPalCusPos = 0;

	// Draw text
	showPaletteGUI.DrawGUIWindow(80, 48, 0, 0, BLACK, WHITE);
	showPaletteGUI.DrawGUILabel(0, 0, " COLOR PALETTE", true, showPaletteGUI.color);
	showPaletteGUI.DrawGUILabel(0, 3, " Current Pallete  : DEFAULT_COLOR_PALETTE", false, showPaletteGUI.color);
	showPaletteGUI.DrawGUILabel(0, 4, " Color ID         : ", false, showPaletteGUI.color);
	showPaletteGUI.DrawGUINumber(20, 4, colPalCusPos, showPaletteGUI.color);
	showPaletteGUI.DrawGUILabel(0, 5, " Red Value        : ", false, showPaletteGUI.color);
	showPaletteGUI.DrawGUINumber(20, 5, console.colorPlalette[colPalCusPos] % 256, showPaletteGUI.color);
	showPaletteGUI.DrawGUILabel(0, 6, " Green Value      : ", false, showPaletteGUI.color);
	showPaletteGUI.DrawGUINumber(20, 6, console.colorPlalette[colPalCusPos] / 256 % 256, showPaletteGUI.color);
	showPaletteGUI.DrawGUILabel(0, 7, " Blue Value       : ", false, showPaletteGUI.color);
	showPaletteGUI.DrawGUINumber(20, 7, console.colorPlalette[colPalCusPos] / 65535, showPaletteGUI.color);

	// Draw color palette
	for (int i = 0; i < 16; i++)
	{
		draw.Rectangle((i * 5) - 6 + xMid / 2, 1 + yMid - showPaletteGUI.yOffsetMid, (i * 5) - 8 + xMid / 2, 3 + yMid - showPaletteGUI.yOffsetMid, 177, 240, false);
		draw.Rectangle((i * 5) - 7 + xMid / 2, 0 + yMid - showPaletteGUI.yOffsetMid, (i * 5) - 9 + xMid / 2, 2 + yMid - showPaletteGUI.yOffsetMid, 219, i, false);

	}

	draw.Point((colPalCusPos * 5) - 7 + xMid / 2, 6 + yMid - showPaletteGUI.yOffsetMid, 24, WHITE);
}