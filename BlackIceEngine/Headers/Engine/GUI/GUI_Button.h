#ifndef INC_GUI_BUTTON_H
#define INC_GUI_BUTTON_H

#include <functional>

typedef enum
{
	Normal,
	Highlighted,
	Activated,
} GUI_ButtonState;

class GUI_Button
{
private:
	Texture* texture;	/* Texture for button */
	Texture* texture_h; /* Texture for when hovering/highlighting button */
	Texture* texture_a; /* Texture for when activating button */
	Vector2f position;
	SDL_Rect buttonRect;
	GUI_ButtonState buttonState; /* Current state of button; whether it's highlighted, activated, or not */
	static const int ACTIVATE_TIME; /* Number of miliseconds */
	Timer activateTimer;
	
	std::function< void() > clickedCallback;

public:
	GUI_Button();
	GUI_Button( Texture* texture, Vector2f position, SDL_Rect buttonRect );
	~GUI_Button();
	void SetTextureH( Texture* texture );
	void SetTextureA( Texture* texture );
	
	// TODO Create callback function to be called when GUI Button is clicked
	void SetClickedCallback( std::function< void() > callback );

	void Render();
	bool MouseHovering();
	bool MouseActivating( MouseButton mouseButton );
};

#endif /* INC_GUI_BUTTON_H */