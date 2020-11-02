#pragma once

namespace editspr
{
	void ColorbarEvents()
	{
		if (input.keyPressed(VK_LEFT)) colorBarCusPos -= 1;
		if (input.keyPressed(VK_RIGHT)) colorBarCusPos += 1;
		if (input.keyPressed(VK_RETURN))
		{
			sound.Play(snd::CLICK);
			for (int i = 0; i < 16; i++)
				if (i == colorBarCusPos) colorForegrund = i;
			for (int i = 16; i < 32; i++)
				if (i == colorBarCusPos) colorBackground = 15 - (i - 16);
		}
	}
}