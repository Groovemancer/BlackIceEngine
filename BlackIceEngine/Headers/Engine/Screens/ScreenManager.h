#pragma once

#include "Screen.h"
#include <stack>

class ScreenManager
{
private:
	std::stack<Screen*> screenStack;

public:
	void CleanUp();
	void AddScreen( Screen* screen );
	void RemoveScreen();
	void Update( int ticks );
	void Render();
};