#include "Engine\Main.h"

const int GUI_Button::ACTIVATE_TIME = 120;

GUI_Button::GUI_Button()
{
	GUI_Button::position = Vector2f();
	buttonState = GUI_ButtonState::Normal;
}

GUI_Button::GUI_Button( Texture* txt, Vector2f position, SDL_Rect buttonRect )
{
	GUI_Button::texture = txt;
	GUI_Button::position = position;
	GUI_Button::buttonRect = buttonRect;
	buttonState = GUI_ButtonState::Normal;
}

GUI_Button::~GUI_Button()
{
	texture->Free();
	texture_h->Free();
	texture_a->Free();

	delete texture, texture_h, texture_a;
}

bool GUI_Button::MouseHovering()
{
	SDL_Point mousePos = InputManager::GetMousePosition();
	
	if ( mousePos.x >= position.x && mousePos.y >= position.y &&
		mousePos.x < ( position.x + buttonRect.w ) && mousePos.y < ( position.y + buttonRect.h ) )
	{
		// If button is Activated, don't set the button state to Highlighted
		if ( buttonState != GUI_ButtonState::Activated )
			buttonState = GUI_ButtonState::Highlighted;
		return true;
	}

	if ( buttonState != GUI_ButtonState::Activated )
	{
		buttonState = GUI_ButtonState::Normal;
	}

	return false;
}

bool GUI_Button::MouseActivating( MouseButton button )
{
	if ( buttonState == GUI_ButtonState::Activated ) return false; // Already activated, return false

	if ( MouseHovering() && InputManager::IsMouseButtonDown( button ) )
	{
		buttonState = GUI_ButtonState::Activated;
		activateTimer.Start();
		OutputDebugString( "Activating Button!" );
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
	if ( buttonState == GUI_ButtonState::Activated &&
		activateTimer.Get_Ticks() > ACTIVATE_TIME )
	{
		std::stringstream str;
		str << "Activate Timer: " << activateTimer.Get_Ticks() << "\n";
		OutputDebugString( str.str().c_str() );
		buttonState = GUI_ButtonState::Normal;
		activateTimer.Stop();
	}

	if ( texture_a != NULL && buttonState == GUI_ButtonState::Activated )
	{
		texture_a->Render( position );
	}
	else if ( texture_h != NULL && buttonState == GUI_ButtonState::Highlighted )
	{
		texture_h->Render( position );
	}
	else
	{
		texture->Render( position, Vector2f(), 0, 1, NULL );
	}
}

