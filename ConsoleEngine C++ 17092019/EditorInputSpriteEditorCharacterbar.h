#pragma once

namespace editspr
{
	void CharacterbarEvents()
	{
		if (input.keyPressed(VK_LEFT))
		{
			if (charCusPos > 0) charCusPos -= 1;
			else charBarPos -= 1;
		}
		if (input.keyPressed(VK_RIGHT))
		{
			if (charCusPos <= (screenWidth / 2) - 2) charCusPos += 1;
			else charBarPos += 1;
		}
	}
}