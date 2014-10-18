#ifndef INC_TESTSCREEN_H
#define INC_TESTSCREEN_H

#include "Engine\GUI\GUI_Button.h"

class TestScreen : public Screen
{
private:
	Texture buttonSelection;
	Texture playButton;
	Texture quitButton;
	Texture background;	
	int selectionIndex;
	static const int BUTTON_COUNT = 2;
	GUI_Button* testButton;
	
public:
	TestScreen();
	~TestScreen();
	void Update( int ticks );
	void Render();
};

#endif /* INC_TESTSCREEN_H */