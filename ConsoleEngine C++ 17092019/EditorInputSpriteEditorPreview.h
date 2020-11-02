#pragma once
namespace editspr
{
	void PreviewInput()
	{
		if (input.keyPressed(VK_F5)){
			editorState = DRAW_EDITOR_SPRITE;
			console.Font(L"Terminal", 16, 16, FF_DONTCARE, FW_NORMAL);
		}
		if (input.keyPressed('0')) console.Font(L"Terminal", 4, 6, FF_DONTCARE, FW_NORMAL);
		if (input.keyPressed('1')) console.Font(L"Terminal", 8, 8, FF_DONTCARE, FW_NORMAL);
		if (input.keyPressed('2')) console.Font(L"Terminal", 12, 16, FF_DONTCARE, FW_NORMAL);
		if (input.keyPressed('3')) console.Font(L"Terminal", 16, 16, FF_DONTCARE, FW_NORMAL);

		if (input.keyState(VK_LEFT))  editspr::xPrePos -= 1;
		if (input.keyState(VK_RIGHT)) editspr::xPrePos += 1;
		if (input.keyState(VK_UP))    editspr::yPrePos -= 1;
		if (input.keyState(VK_DOWN))  editspr::yPrePos += 1;
	}
}