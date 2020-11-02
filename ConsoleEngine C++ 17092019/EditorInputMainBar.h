#pragma once
void MainBarEvents()
{
	// Mainbar controls
	if (input.keyPressed(VK_LEFT)) mainBarCusPos -= 1;
	if (input.keyPressed(VK_RIGHT)) mainBarCusPos += 1;

	// Mainbar enter events 
	if (input.keyPressed(VK_RETURN))
	{
		sound.Play(snd::CLICK_FORWARD);
		menuState = TOOL_MENU;
		toolBarCusPos = 0;
		switch (mainBarCusPos) {
			//************************************//MAINBAR EVENTS//************************************//
		case MAINBAR_EXIT:
			exitState = true;
			break;
		default: break;
		}
	}
}