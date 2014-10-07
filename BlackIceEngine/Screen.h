#ifndef INC_SCREEN_H
#define INC_SCREEN_H

class Screen
{
protected:
	bool finished;
	bool disposable;
	Screen* nextScreen;
public:
	Screen();
	~Screen();
	virtual void Update( int ticks );
	virtual void Render();
	bool IsFinished();
	bool IsDisposable();
	Screen* GetNextScreen();
};

#endif /* INC_SCREEN_H */