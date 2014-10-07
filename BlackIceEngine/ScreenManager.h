#ifndef INC_SCREENMANAGER_H
#define INC_SCREENMANAGER_H

#include "Screen.h"
#include <stack>

class ScreenManager
{
private:
	std::stack<Screen*> screenStack;

public:
	void AddScreen( Screen* screen );
	void RemoveScreen();
	void Update( int ticks );
	void Render();
};

#endif /* INC_SCREENMANAGER_H */