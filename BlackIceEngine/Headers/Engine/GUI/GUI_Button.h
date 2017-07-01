#pragma once

typedef enum
{
	NORMAL,
	HIGHLIGHTED,
	ACTIVATED,
} GUI_ButtonState;

class GUI_Button
{
private:
	GUI_Skin* guiSkin; /* Creates button from skin instead of from regular textures */
	Texture* texture;	/* Texture for button */
	Texture* texture_h; /* Texture for when hovering/highlighting button */
	Texture* texture_a; /* Texture for when activating button */
	Vector2f position;
	SDL_Rect buttonRect;
	GUI_ButtonState buttonState; /* Current state of button; whether it's highlighted, activated, or not */
	static const int ACTIVATE_TIME; /* Number of miliseconds */
	Timer activateTimer;
	
	boost::function<void()> clickedCallback;
	std::function<void()> clickedCallback2;

public:
	GUI_Button();
	GUI_Button( Texture* texture, Vector2f position, SDL_Rect buttonRect );
	GUI_Button( GUI_Skin* guiSkin, Vector2f position, SDL_Rect buttonRect );
	~GUI_Button();
	void SetTextureH( Texture* texture );
	void SetTextureA( Texture* texture );
	
	// TODO: Create callback function to be called when GUI Button is clicked
	void SetClickedCallback( boost::function<void()> callback ) { clickedCallback = callback; }
	void SetClickedCallback( std::function<void()> callback) { clickedCallback2 = callback; }

	void Render();
	bool MouseHovering();
	bool MouseActivating( MouseButton mouseButton );
};