#ifndef INC_INPUTMANAGER_H
#define INC_INPUTMANAGER_H

#include "Keys.h"
#include <map>

class InputManager
{
public:
	static bool IsKeyHeld( Key key );
	static bool IsKeyDown( Key key );
	static bool IsKeyUp( Key key );
	static bool Update();
};

#endif /* INC_INPUTMANAGER_H */