#include "Engine\Main.h"

std::map<int, char> keyStates;
std::map<int, char> mouseButtonStates;
Uint8 mouseClicks;

bool InputManager::IsKeyHeld( Key key )
{
	if ( keyStates[ key ] == 'h' )
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyDown( Key key )
{
	if ( keyStates[ key ] == 'd' )
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyUp( Key key )
{
	if ( keyStates[ key ] == 'u' )
	{
		return true;
	}

	return false;
}

bool InputManager::IsMouseButtonHeld( MouseButton button, bool doubleClick )
{	
	if ( mouseButtonStates[ button ] == 'h' )
	{
		if ( doubleClick )
		{
			return mouseClicks == 2;
		}
		else {
			return true;
		}
	}

	return false;
}

bool InputManager::IsMouseButtonDown( MouseButton button, bool doubleClick )
{
	if ( mouseButtonStates[ button ] == 'd' )
	{		
		if ( doubleClick )
		{
			return mouseClicks == 2;
		}
		else {
			return true;
		}
	}

	return false;
}

bool InputManager::IsMouseButtonUp( MouseButton button, bool doubleClick )
{
	if ( mouseButtonStates[ button ] == 'u' )
	{
		if ( doubleClick )
		{
			return mouseClicks == 2;
		}
		else {
			return true;
		}
	}

	return false;
}

SDL_Point InputManager::GetMousePosition()
{
	SDL_Point pos;

	SDL_GetMouseState( &pos.x, &pos.y );

	return pos;
}

bool InputManager::Update()
{
	SDL_Event event;
	std::vector< Key > keys;
	std::vector< MouseButton > mouseButtons;

	while ( SDL_PollEvent( &event ) )
	{
		switch ( event.type )
		{
			case SDL_QUIT:
				return true;
				break;
			case SDL_KEYDOWN:
				{
					keyStates[ event.key.keysym.sym ] = 'd';
					keys.push_back( Key(event.key.keysym.sym) );
				}
				break;
			case SDL_KEYUP:
				{
					keyStates[ event.key.keysym.sym ] = 'u';
					keys.push_back( Key(event.key.keysym.sym) );
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				{
					mouseButtonStates[ event.button.button ] = 'd';
					mouseButtons.push_back( MouseButton(event.button.button) );
				}
				break;
			case SDL_MOUSEBUTTONUP:
				{
					mouseButtonStates[ event.button.button ] = 'u';
					mouseButtons.push_back( MouseButton(event.button.button) );
				}
				break;
			default:
				break;
		}
	}

	for ( std::map<int, char>::iterator itr = keyStates.begin(); itr != keyStates.end(); itr++ )
	{
		// puts no status flag
		if ( itr->second == 'u' )
		{
			bool keyFound = false;
			for ( int i = 0; i < int(keys.size()); i++ )
			{
				if ( keys[ i ] == itr->first )
				{
					keyFound = true;
					break;
				}
			}

			if ( !keyFound )
			{
				itr->second = 'n';
			}
		}
		else if ( itr->second == 'd' )
		{
			bool keyFound = false;
			for ( int i = 0; i < int(keys.size()); i++ )
			{
				if ( keys[ i ] == itr->first )
				{
					keyFound = true;
					break;
				}
			}

			if ( !keyFound )
			{
				itr->second = 'h';
			}
		}
	}

	for ( std::map<int, char>::iterator itr = mouseButtonStates.begin(); itr != mouseButtonStates.end(); itr++ )
	{
		// puts no status flag
		if ( itr->second == 'u' )
		{
			bool buttonFound = false;
			for ( int i = 0; i < int(mouseButtons.size()); i++ )
			{
				if ( mouseButtons[ i ] == itr->first )
				{
					buttonFound = true;
					break;
				}
			}

			if ( !buttonFound )
			{
				itr->second = 'n';
			}
		}
		else if ( itr->second == 'd' )
		{
			bool buttonFound = false;
			for ( int i = 0; i < int(mouseButtons.size()); i++ )
			{
				if ( mouseButtons[ i ] == itr->first )
				{
					buttonFound = true;
					break;
				}
			}

			if ( !buttonFound )
			{
				itr->second = 'h';
			}
		}
	}

	return false;
}