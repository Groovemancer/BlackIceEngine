#ifndef INC_GAME_H
#define INC_GAME_H

#include <SDL.h>
#include "Camera.h"
#include "ScreenManager.h"
#include <string>
#include <vector>

// The Game
class Game
{
private:
	static int screenWidth;
	static int screenHeight;

	bool Init_GL();
	bool ReadConfigFile();
public:
	// The camera that determines what we're rendering to the screen
	static Camera camera;
	// Manages all the different types of "screens"
	static ScreenManager screenManager;
	
	// The window we're rendering to
	SDL_Window* window;

	// OpenGL context
	SDL_GLContext context;

	void Clear_Screen( SDL_Color color );
	void Clear_Screen( float r, float g, float b, float a );
	void Update_Screen();
	bool Initialize();
	void Set_Window_Title( std::string title );
	void Clean_Up();
	static int GetWidth();
	static int GetHeight();
};

#endif