#include "Engine\Main.h"

TestScreen::TestScreen()
	: Screen()
{
	buttonSelection.Load_From_File( "Resources\\Textures\\GUI\\buttonSelection.png" );
	playButton.Load_From_File( "Resources\\Textures\\GUI\\playButton.png" );
	quitButton.Load_From_File( "Resources\\Textures\\GUI\\quitButton.png" );
	background.Load_From_File( "Resources\\Textures\\mainMenuBackground.png" );
	
	Texture* testBtnTx = new Texture();
	Texture* testBtnTx_a = new Texture();
	Texture* testBtnTx_h = new Texture();
	
	testBtnTx->Load_From_File( "Resources\\Textures\\GUI\\testButton_n.png" );
	testBtnTx_a->Load_From_File( "Resources\\Textures\\GUI\\testButton_a.png" );
	testBtnTx_h->Load_From_File( "Resources\\Textures\\GUI\\testButton_h.png" );
	
	SDL_Rect btnRect = { 0, 0, 192, 96 };

	testButton = new GUI_Button( testBtnTx, Vector2f( ( Game::GetWidth() / 2 ) - ( btnRect.w / 2 ), 120 ), btnRect );
	testButton->SetTextureA( testBtnTx_a );
	testButton->SetTextureH( testBtnTx_h );
	testButton->SetClickedCallback( TestFunc );

	//TODO: Add new screen to transition to from Play button
	selectionIndex = 0;
}

TestScreen::~TestScreen()
{
	Screen::~Screen();
	delete testButton;
}

void TestScreen::Update( int ticks )
{
	if ( InputManager::IsKeyDown( Key::KEY_DOWN ) )
	{
		selectionIndex++;
		if ( selectionIndex >= BUTTON_COUNT )
		{
			selectionIndex = 0;
		}
	}
	if ( InputManager::IsKeyDown( Key::KEY_UP ) )
	{
		selectionIndex--;
		if ( selectionIndex < 0 )
		{
			selectionIndex = BUTTON_COUNT - 1;
		}
	}
	if ( InputManager::IsKeyDown( Key::KEY_SPACE ) ||
		InputManager::IsKeyDown( Key::KEY_RETURN ) )
	{
		if ( selectionIndex == 0 )
		{
			finished = true;
			MainGame::Quit();
			return;
		}
		else if ( selectionIndex == 1 )
		{
			MainGame::Quit();
			return;
		}
	}

	if ( InputManager::IsKeyDown( Key::KEY_f ) )
	{
		// Check for memory leaks
	}

	if ( testButton->MouseHovering() )
	{
		// Do something when hovering it
	}
	if ( testButton->MouseActivating( MouseButton::MOUSE_BUTTON_LEFT ) )
	{
		// Do something when left clicking on it
		OutputDebugString( "Left clicked the button!\n" );
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

	testButton->Render();
}

void TestScreen::TestFunc()
{
	OutputDebugString( "This is my callback function!\n" );
}