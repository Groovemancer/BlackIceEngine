#include "Engine\Main.h"

Screen::Screen()
{
	finished = false;
	disposable = false;
	nextScreen = NULL;
}

Screen::~Screen()
{
	delete nextScreen;
}

void Screen::Update( int ticks )
{
}

void Screen::Render()
{
}

bool Screen::IsFinished()
{
	return finished;
}

bool Screen::IsDisposable()
{
	return disposable;
}

Screen* Screen::GetNextScreen()
{
	return nextScreen;
}