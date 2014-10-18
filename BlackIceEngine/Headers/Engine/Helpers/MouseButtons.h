#ifndef MOUSE_BUTTONS
#define MOUSE_BUTTONS

#include <SDL.h>

/* Maps all mouse buttons to sdl mouse buttons */
typedef enum {
	MOUSE_BUTTON_LEFT		= SDL_BUTTON_LEFT,		/* Left Mouse Button */
	MOUSE_BUTTON_MIDDLE		= SDL_BUTTON_MIDDLE,	/* Middle Mouse Button */
	MOUSE_BUTTON_RIGHT		= SDL_BUTTON_RIGHT,		/* Right Mouse Button */
	MOUSE_BUTTON_X1			= SDL_BUTTON_X1,		/* Extra Mouse Button 1 */
	MOUSE_BUTTON_X2			= SDL_BUTTON_X2,		/* Extra Mouse Button 2 */
} MouseButton;

#endif