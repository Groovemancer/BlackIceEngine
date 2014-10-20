#include "Engine\Main.h"

Game MainGame::game;
bool MainGame::quit;
Timer MainGame::delta;

bool MainGame::Initialize()
{
	// Initialize
	if ( game.Initialize() == false )
	{
		return false;
	}

	// Game title goes in here
	game.Set_Window_Title( "Black Ice Engine" );

	// Load the files
	if ( !LoadFiles() )
	{
		return false;
	}

	// Start delta timer
	delta.Start();

	return true;
}

void MainGame::Quit()
{
	game.screenManager.CleanUp();
	quit = true;
	OutputDebugString( "Quiting...\n" );
}

bool MainGame::LoadFiles()
{
	game.screenManager.AddScreen( new TestScreen() );

	// If everything loaded fine
	return true;
}

void MainGame::GameLoop()
{
	// While the user hasn't quit
	while ( !quit )
	{
		quit = InputManager::Update();
		
		game.screenManager.Update( delta.Get_Ticks() );

		if ( quit )
			break;
		
		// Restart delta timer
		delta.Start();

		// Renders screen
		Render();
	}

	// Clean up
	game.Clean_Up();
}

void MainGame::Render()
{
	SDL_Color color = { 0x64, 0x95, 0xED };

	// Clear screen for rendering
	game.Clear_Screen( color );

	// Render the top screen
	game.screenManager.Render();

	game.Update_Screen();
}

Game MainGame::Game()
{
	return game;
}