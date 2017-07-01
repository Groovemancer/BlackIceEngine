#pragma once

class Screen
{
protected:
	bool finished;
	bool disposable;
	Screen* nextScreen;
public:
	Screen();
	virtual ~Screen();
	virtual void Update( int ticks );
	virtual void Render();
	bool IsFinished();
	bool IsDisposable();
	Screen* GetNextScreen();
};