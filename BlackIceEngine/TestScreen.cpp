#include "Main.h"

TestScreen::TestScreen()
	: Screen()
{
	buttonSelection.Load_From_File( "buttonSelection.png" );
	playButton.Load_From_File( "playButton.png" );
	quitButton.Load_From_File( "quitButton.png" );
	background.Load_From_File( "mainMenuBackground.png" );

	//TODO: Add new screen to transition to from Play button
	selectionIndex = 0;
}

void TestScreen::Update( int ticks )
{
	if ( InputManager::IsKeyDown( KEY_DOWN ) )
	{
		selectionIndex++;
		if ( selectionIndex >= BUTTON_COUNT )
		{
			selectionIndex = 0;
		}
	}
	if ( InputManager::IsKeyDown( KEY_UP ) )
	{
		selectionIndex--;
		if ( selectionIndex < 0 )
		{
			selectionIndex = BUTTON_COUNT - 1;
		}
	}
	if ( InputManager::IsKeyDown( KEY_SPACE ) ||
		InputManager::IsKeyDown( KEY_RETURN ) )
	{
		if ( selectionIndex == 0 )
		{
			//finished = true;
			MainGame::Quit();
		}
		else if ( selectionIndex == 1 )
		{
			MainGame::Quit();
		}
	}
}

void TestScreen::Render()
{
	background.Render( Vector2f( 0, 0 ) );

	int centerX = Game::GetWidth() / 2;
	int centerY = Game::GetHeight() / 2;
	playButton.Render(
		Vector2f( float(centerX - ( playButton.GetWidth() / 2 ) ), float( centerY ) ) );
	quitButton.Render(
		Vector2f( float( centerX - ( quitButton.GetWidth() / 2 ) ), float( centerY + ( quitButton.GetHeight() * 1.5f ) ) ) );

	int y = int( selectionIndex * ( buttonSelection.GetHeight() * 1.5f ) );
	
	buttonSelection.Render(
		Vector2f( float( centerX - ( buttonSelection.GetWidth() / 2 ) ), float( centerY + y ) ) );
}