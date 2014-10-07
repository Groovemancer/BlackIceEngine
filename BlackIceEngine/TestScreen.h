#ifndef INC_TESTSCREEN_H
#define INC_TESTSCREEN_H

class TestScreen : public Screen
{
private:
	Texture buttonSelection;
	Texture playButton;
	Texture quitButton;
	Texture background;
	int selectionIndex;
	static const int BUTTON_COUNT = 2;
public:
	TestScreen();
	void Update( int ticks );
	void Render();
};

#endif /* INC_TESTSCREEN_H */