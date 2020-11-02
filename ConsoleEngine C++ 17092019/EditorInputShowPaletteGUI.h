#pragma once
void ShowPaletteGUIEvents()
{
	if (input.keyPressed(VK_LEFT)) colPalCusPos -= 1;
	if (input.keyPressed(VK_RIGHT)) colPalCusPos += 1;
}