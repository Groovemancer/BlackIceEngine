#include "Main.h"

int main( int argc, char* args[] )
{
	OutputDebugString( "TEST?!\n" );
	if ( !MainGame::Initialize() )
	{
		return 1;
	}

	// Run the game
	MainGame::GameLoop();

	return 0;
}