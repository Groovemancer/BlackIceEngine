#include "Main.h"

std::map<int, char> keyStates;

bool InputManager::IsKeyHeld( Key key )
{
	if( keyStates[ key ] == 'h' )
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyDown( Key key )
{
	if( keyStates[ key ] == 'd' )
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyUp( Key key )
{
	if( keyStates[ key ] == 'u' )
	{
		return true;
	}

	return false;
}

bool InputManager::Update()
{
	SDL_Event event;
	std::vector< Key > keys;

	while ( SDL_PollEvent( &event ) )
	{
		switch ( event.type )
		{
			case SDL_QUIT:
				return true;
				break;
			case SDL_KEYDOWN:
				keyStates[ event.key.keysym.sym ] = 'd';
				keys.push_back( Key(event.key.keysym.sym) );
				break;
			case SDL_KEYUP:
				keyStates[ event.key.keysym.sym ] = 'u';
				keys.push_back( Key(event.key.keysym.sym) );
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

	return false;
}