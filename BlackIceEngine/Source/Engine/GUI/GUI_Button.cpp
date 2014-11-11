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

GUI_Button::GUI_Button( GUI_Skin* guiSkin, Vector2f position, SDL_Rect buttonRect )
{
	texture = NULL;
	texture_h = NULL;
	texture_a = NULL;
	GUI_Button::guiSkin = guiSkin;
	GUI_Button::position = position;
	GUI_Button::buttonRect = buttonRect;
	buttonState = NORMAL;
}

GUI_Button::~GUI_Button()
{
	if ( texture != NULL )
		texture->Free();
	if ( texture_h != NULL )
		texture_h->Free();
	if ( texture_a != NULL )
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

	if ( guiSkin != NULL )
	{
		if ( guiSkin->btn_a_texture != NULL && buttonState == ACTIVATED )
		{
			// Top-left
			SDL_Rect tl = { 0, 0, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position, Vector2f::Zero(), 0, 1, &tl );

			// Top-mid
			SDL_Rect tm = { guiSkin->btn_a_width, 0, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( buttonRect.w - ( guiSkin->btn_a_width * 2 ), guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position + Vector2f( guiSkin->btn_a_width, 0 ), Vector2f::Zero(), 0, 1, &tm );

			// Top-right
			SDL_Rect tr = { guiSkin->btn_a_width * 2, 0, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_a_width, 0 ), Vector2f::Zero(), 0, 1, &tr );

			// Mid-left
			SDL_Rect ml = { 0, guiSkin->btn_a_height, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, buttonRect.h - ( guiSkin->btn_a_height * 2 ) );
			guiSkin->btn_a_texture->Render( position + Vector2f( 0, guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &ml );

			// Mid-mid
			SDL_Rect mm = { guiSkin->btn_a_width, guiSkin->btn_a_height, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( buttonRect.w - ( guiSkin->btn_a_width * 2 ), buttonRect.h - ( guiSkin->btn_a_height * 2 ) );
			guiSkin->btn_a_texture->Render( position + Vector2f( guiSkin->btn_a_width, guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &mm );

			// Mid-right
			SDL_Rect mr = { guiSkin->btn_a_width * 2, guiSkin->btn_a_height, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, buttonRect.h - ( guiSkin->btn_a_height * 2 ) );
			guiSkin->btn_a_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_a_width, guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &mr );

			// Bot-left
			SDL_Rect bl = { 0, guiSkin->btn_a_height * 2, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position + Vector2f( 0, buttonRect.h - guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &bl );

			// Bot-mid
			SDL_Rect bm = { guiSkin->btn_a_width, guiSkin->btn_a_height * 2, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( buttonRect.w - ( guiSkin->btn_a_width * 2 ), guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position + Vector2f( guiSkin->btn_a_width, buttonRect.h - guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &bm );

			// Bot-right
			SDL_Rect br = { guiSkin->btn_a_width * 2, guiSkin->btn_a_height * 2, guiSkin->btn_a_width, guiSkin->btn_a_height };
			guiSkin->btn_a_texture->Stretch( guiSkin->btn_a_width, guiSkin->btn_a_height );
			guiSkin->btn_a_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_a_width, buttonRect.h - guiSkin->btn_a_height ), Vector2f::Zero(), 0, 1, &br );
		}
		else if ( guiSkin->btn_h_texture != NULL && buttonState == HIGHLIGHTED )
		{
			// Top-left
			SDL_Rect tl = { 0, 0, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position, Vector2f::Zero(), 0, 1, &tl );

			// Top-mid
			SDL_Rect tm = { guiSkin->btn_h_width, 0, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( buttonRect.w - ( guiSkin->btn_h_width * 2 ), guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position + Vector2f( guiSkin->btn_h_width, 0 ), Vector2f::Zero(), 0, 1, &tm );

			// Top-right
			SDL_Rect tr = { guiSkin->btn_h_width * 2, 0, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_h_width, 0 ), Vector2f::Zero(), 0, 1, &tr );

			// Mid-left
			SDL_Rect ml = { 0, guiSkin->btn_h_height, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, buttonRect.h - ( guiSkin->btn_h_height * 2 ) );
			guiSkin->btn_h_texture->Render( position + Vector2f( 0, guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &ml );

			// Mid-mid
			SDL_Rect mm = { guiSkin->btn_h_width, guiSkin->btn_h_height, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( buttonRect.w - ( guiSkin->btn_h_width * 2 ), buttonRect.h - ( guiSkin->btn_h_height * 2 ) );
			guiSkin->btn_h_texture->Render( position + Vector2f( guiSkin->btn_h_width, guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &mm );

			// Mid-right
			SDL_Rect mr = { guiSkin->btn_h_width * 2, guiSkin->btn_h_height, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, buttonRect.h - ( guiSkin->btn_h_height * 2 ) );
			guiSkin->btn_h_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_h_width, guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &mr );

			// Bot-left
			SDL_Rect bl = { 0, guiSkin->btn_h_height * 2, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position + Vector2f( 0, buttonRect.h - guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &bl );

			// Bot-mid
			SDL_Rect bm = { guiSkin->btn_h_width, guiSkin->btn_h_height * 2, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( buttonRect.w - ( guiSkin->btn_h_width * 2 ), guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position + Vector2f( guiSkin->btn_h_width, buttonRect.h - guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &bm );

			// Bot-right
			SDL_Rect br = { guiSkin->btn_h_width * 2, guiSkin->btn_h_height * 2, guiSkin->btn_h_width, guiSkin->btn_h_height };
			guiSkin->btn_h_texture->Stretch( guiSkin->btn_h_width, guiSkin->btn_h_height );
			guiSkin->btn_h_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_h_width, buttonRect.h - guiSkin->btn_h_height ), Vector2f::Zero(), 0, 1, &br );
		}
		else
		{
			// Top-left
			SDL_Rect tl = { 0, 0, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position, Vector2f::Zero(), 0, 1, &tl );

			// Top-mid
			SDL_Rect tm = { guiSkin->btn_n_width, 0, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( buttonRect.w - ( guiSkin->btn_n_width * 2 ), guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position + Vector2f( guiSkin->btn_n_width, 0 ), Vector2f::Zero(), 0, 1, &tm );

			// Top-right
			SDL_Rect tr = { guiSkin->btn_n_width * 2, 0, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_n_width, 0 ), Vector2f::Zero(), 0, 1, &tr );

			// Mid-left
			SDL_Rect ml = { 0, guiSkin->btn_n_height, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, buttonRect.h - ( guiSkin->btn_n_height * 2 ) );
			guiSkin->btn_n_texture->Render( position + Vector2f( 0, guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &ml );

			// Mid-mid
			SDL_Rect mm = { guiSkin->btn_n_width, guiSkin->btn_n_height, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( buttonRect.w - ( guiSkin->btn_n_width * 2 ), buttonRect.h - ( guiSkin->btn_n_height * 2 ) );
			guiSkin->btn_n_texture->Render( position + Vector2f( guiSkin->btn_n_width, guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &mm );

			// Mid-right
			SDL_Rect mr = { guiSkin->btn_n_width * 2, guiSkin->btn_n_height, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, buttonRect.h - ( guiSkin->btn_n_height * 2 ) );
			guiSkin->btn_n_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_n_width, guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &mr );

			// Bot-left
			SDL_Rect bl = { 0, guiSkin->btn_n_height * 2, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position + Vector2f( 0, buttonRect.h - guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &bl );

			// Bot-mid
			SDL_Rect bm = { guiSkin->btn_n_width, guiSkin->btn_n_height * 2, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( buttonRect.w - ( guiSkin->btn_n_width * 2 ), guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position + Vector2f( guiSkin->btn_n_width, buttonRect.h - guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &bm );

			// Bot-right
			SDL_Rect br = { guiSkin->btn_n_width * 2, guiSkin->btn_n_height * 2, guiSkin->btn_n_width, guiSkin->btn_n_height };
			guiSkin->btn_n_texture->Stretch( guiSkin->btn_n_width, guiSkin->btn_n_height );
			guiSkin->btn_n_texture->Render( position + Vector2f( buttonRect.w - guiSkin->btn_n_width, buttonRect.h - guiSkin->btn_n_height ), Vector2f::Zero(), 0, 1, &br );
		}
	}
	else
	{
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
}