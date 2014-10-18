#ifndef INC_TEXTURE_H
#define INC_TEXTURE_H

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
	void Set_Size();
public:
	Texture();
	~Texture();
	bool Load_From_File( std::string path, Uint32 colorkey = 0xffff00ff ); /* Default Colorkey: Magenta */
	bool Load_From_Pixels( GLuint* pixels, GLuint width, GLuint height );
	void Apply_Colorkey( Uint32 colorKey );
	void Free();
	void Render( Vector2f position, Vector2f origin = Vector2f::Zero(), float rotation = 0, float scale = 1, SDL_Rect* frameRect = NULL );
	GLuint GetID();
	int GetWidth();
	int GetHeight();

	// Old stuff
	/*
	int w;
	int h;

	void Apply_Colorkey( Uint32 colorKey );
	void Load_Image( std::string filename, Uint32 colorkey = 0x00ff00ff ); // Default Colorkey: Magenta
	void Render( Vector2f position, Vector2f origin, float rotation, float scale, SDL_Rect* frameRect = NULL );
	*/
};

#endif /* INC_TEXTURE_H */