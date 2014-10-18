#ifndef INC_INPUTMANAGER_H
#define INC_INPUTMANAGER_H

#include "Keys.h"
#include "MouseButtons.h"
#include <map>

class InputManager
{
public:
	static bool IsKeyHeld( Key key );
	static bool IsKeyDown( Key key );
	static bool IsKeyUp( Key key );
	static bool IsMouseButtonHeld( MouseButton button, bool doubleClick = false );
	static bool IsMouseButtonDown( MouseButton button, bool doubleClick = false );
	static bool IsMouseButtonUp( MouseButton button, bool doubleClick = false );
	static SDL_Point GetMousePosition();
	static bool Update();
};

#endif /* INC_INPUTMANAGER_H */