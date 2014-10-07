#ifndef INC_MAINGAME_H
#define INC_MAINGAME_H

#include "Game.h"
#include "Timer.h"

class MainGame
{
private:
	// Quit flag
	static bool quit;

	// Keeps track of time since last rendering
	static Timer delta;

	// The game itself
	static Game game;

	// The event structure that will be used
	SDL_Event event;

	// Load some initial files
	static bool LoadFiles();

	// Renders everything
	static void Render();
public:
	// Sets up everything
	static bool Initialize();
	static void Quit();
	static void GameLoop();

	static Game Game();
};

#endif /* INC_MAINGAME_H */