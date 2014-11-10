#include "Engine\Main.h"

const int GUI_Button::ACTIVATE_TIME = 120;

GUI_Button::GUI_Button()
{
	GUI_Button::position = Vector2f();
	buttonState = NORMAL;
}

GUI_Button::GUI_Button( Texture* txt, Vector2f position, SDL_Rect buttonRect )
{
	GUI_Button::texture = txt;
	GUI_Button::position = position;
	GUI_Button::buttonRect = buttonRect;
	buttonState = NORMAL;
}

GUI_Button::~GUI_Button()
{
	texture->Free();
	texture_h->Free();
	texture_a->Free();

	delete texture;
	delete texture_h;
	delete texture_a;
}

bool GUI_Button::MouseHovering()
{
	SDL_Point mousePos = InputManager::GetMousePosition();
	
	if ( mousePos.x >= position.x && mousePos.y >= position.y &&
		mousePos.x < ( position.x + buttonRect.w ) && mousePos.y < ( position.y + buttonRect.h ) )
	{
		// If button is ACTIVATED, don't set the button state to HIGHLIGHTED
		if ( buttonState != ACTIVATED )
			buttonState = HIGHLIGHTED;
		return true;
	}

	if ( buttonState != ACTIVATED )
	{
		buttonState = NORMAL;
	}

	return false;
}

bool GUI_Button::MouseActivating( MouseButton button )
{
	if ( buttonState == ACTIVATED ) return false; // Already activated, return false

	if ( MouseHovering() && InputManager::IsMouseButtonDown( button ) )
	{
		buttonState = ACTIVATED;
		activateTimer.Start();
		OutputDebugString( "Activating Button!\n" );

		// Callback function is called here. Currently only setup to work with void functions.
		clickedCallback();
		return true;
	}
	return false;
}

void GUI_Button::SetTextureH( Texture* txt )
{
	texture_h = txt;
}

void GUI_Button::SetTextureA( Texture* txt )
{
	texture_a = txt;
}

void GUI_Button::Render()
{
	if ( buttonState == ACTIVATED &&
		activateTimer.Get_Ticks() > ACTIVATE_TIME )
	{
		buttonState = NORMAL;
		activateTimer.Stop();
	}

	if ( texture_a != NULL && buttonState == ACTIVATED )
	{
		texture_a->Render( position );
	}
	else if ( texture_h != NULL && buttonState == HIGHLIGHTED )
	{
		texture_h->Render( position );
	}
	else
	{
		texture->Render( position, Vector2f(), 0, 1, NULL );
	}
}