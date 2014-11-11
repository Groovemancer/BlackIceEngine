#include "Engine\Main.h"

GUI_Skin::GUI_Skin()
{
	// Set some defaults

	// The neutral, untouched button
	btn_n_texture = new Texture();
	btn_n_texture->Load_From_File( "Resources\\Textures\\GUI\\gui_skin_button_n.png" );
	btn_n_width = 16;
	btn_n_height = 16;

	// The button that's being hovered over
	btn_h_texture = new Texture();
	btn_h_texture->Load_From_File( "Resources\\Textures\\GUI\\gui_skin_button_h.png" );
	btn_h_width = 16;
	btn_h_height = 16;

	// The button that's being clicked/activated
	btn_a_texture = new Texture();
	btn_a_texture->Load_From_File( "Resources\\Textures\\GUI\\gui_skin_button_a.png" );
	btn_a_width = 16;
	btn_a_height = 16;
}

GUI_Skin::~GUI_Skin()
{
	btn_n_texture->Free();
	delete btn_n_texture;

	btn_h_texture->Free();
	delete btn_h_texture;

	btn_a_texture->Free();
	delete btn_a_texture;
}