#include "EngineCore.h"
#include "Input.h"
#include <conio.h>

///////////////////////////////////////////////////////////////////////
//						Input methods								 //
///////////////////////////////////////////////////////////////////////

Input::Input() {};

// Input key hold
bool Input::keyState(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;
	else return false;
}

// Input key hold delayed loop
bool Input::keyStateDelayedLoop(int key)
{
	if (GetAsyncKeyState(key) & 0x0001)
		return true;
	else return false;
}

// Input key pressed
bool Input::keyPressed(int key)
{

	if (GetAsyncKeyState(key) & 0x0001)
		return true;
	else return false;
	
	//bool keyIsPressed;
	//if (!GetAsyncKeyState(key)) keyIsPressed = false;
	//
	//if ((GetAsyncKeyState(key) & 0x8000) && (keyIsPressed == false))
	//{
	//	keyIsPressed = true; 
	//	return true;
	//}
	//else return false;
	
}

