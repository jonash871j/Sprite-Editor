#pragma once
namespace editspr
{
	void Preview()
	{
		sprite.SpriteDraw(xPrePos, 1 + yPrePos);
		drawMainBar(2);
		drawFooter(fbPreview, 3, 3);

		backgroundColor = BLACK;
		backgroundTexture = 176;
	}
}