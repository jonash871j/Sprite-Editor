#pragma once
class Input
{
public:
	Input();

	// Input
	bool keyState(int key);

	bool keyStateDelayedLoop(int key);

	bool keyPressed(int key);
};

