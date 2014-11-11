#ifndef INC_GUI_SKIN_H
#define INC_GUI_SKIN_H

class GUI_Skin
{
public:	
	// The Button Skin texture is broken down to 9 rectangles with each rectangle
	// being either a corner or side to the button stretched to fit the size of the button

	// The neutral, untouched button
	Texture* btn_n_texture;
	int btn_n_width;
	int btn_n_height;

	// The button that's being hovered over
	Texture* btn_h_texture;
	int btn_h_width;
	int btn_h_height;

	// The button that's being clicked/activated
	Texture* btn_a_texture;
	int btn_a_width;
	int btn_a_height;

	GUI_Skin();
	~GUI_Skin();
};

#endif