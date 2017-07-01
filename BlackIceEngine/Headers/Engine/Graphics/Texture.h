#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Engine\Helpers\Vector2f.h"
#include <string>

// Texture data type
class Texture
{
private:
	GLuint textureID;

	GLuint width;
	GLuint height;
	int stretchWidth;
	int stretchHeight;
	void Set_Size();
public:
	Texture();
	~Texture();
	bool Load_From_File( std::string path, Uint32 colorkey = 0xFFFF00FF ); /* Default Colorkey: Magenta */
	bool Load_From_Pixels( GLuint* pixels, GLuint width, GLuint height );
	void Apply_Colorkey( Uint32 colorKey );
	void Free();
	void Stretch( int w, int h ) { stretchWidth = w; stretchHeight = h; }
	void StretchWidth( int w ) { stretchWidth = w; }
	void StretchHeight( int h ) { stretchHeight = h; }
	void Render( Vector2f position, Vector2f origin = Vector2f::Zero(), float rotation = 0, float scale = 1, SDL_Rect* frameRect = NULL );
	GLuint GetID();
	int GetWidth();
	int GetHeight();
};