#include "Engine\Main.h"

int main( int argc, char* args[] )
{
	if ( !MainGame::Initialize() )
	{
		return 1;
	}

	// Run the game
	MainGame::GameLoop();

	return 0;
}