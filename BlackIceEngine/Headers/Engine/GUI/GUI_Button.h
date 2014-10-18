#ifndef INC_GUI_BUTTON_H
#define INC_GUI_BUTTON_H

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
//#define ACTIVATE_TIME = 30; /* Number of miliseconds */
	static const int ACTIVATE_TIME;
	Timer activateTimer;

public:
	GUI_Button();
	GUI_Button( Texture* texture, Vector2f position, SDL_Rect buttonRect );
	~GUI_Button();
	void SetTextureH( Texture* texture );
	void SetTextureA( Texture* texture );
	void Render();
	bool MouseHovering();
	bool MouseActivating( MouseButton mouseButton );
};

#endif /* INC_GUI_BUTTON_H */