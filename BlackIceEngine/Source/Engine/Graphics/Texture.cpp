#include "Engine\Main.h"

Texture::Texture()
{
	// Initialize texture ID
	textureID = 0;

	// Initialize texture dimensions
	width = 0;
	height = 0;
}

Texture::~Texture()
{
	// Free texture data if needed
	Free();
}

bool Texture::Load_From_File( std::string path, Uint32 colorkey )
{
	// Texture loading success
	bool textureLoaded = false;

	// Generate and set current image ID
	ILuint imgID = 0;
	ilGenImages( 1, &imgID );
	ilBindImage( imgID );

	// Load image
	ILboolean success = ilLoadImage( path.c_str() );

	// Image loaded successfully
	if ( success == IL_TRUE )
	{
		// Convert image to RGBA
		success = ilConvertImage( IL_RGBA, IL_UNSIGNED_BYTE );
		if ( success == IL_TRUE )
		{
			// Create texture from file pixels
			textureLoaded = Load_From_Pixels( (GLuint*)ilGetData(), (GLuint)ilGetInteger( IL_IMAGE_WIDTH ), (GLuint)ilGetInteger( IL_IMAGE_HEIGHT ) );						
		}

		// Sets the Texture's width/height to be used throughout its functionality
		Texture::Set_Size();		

		// Applies the color key to the texture making all pixels that match the color key to completely transparent
		Texture::Apply_Colorkey( colorkey ); // Default is Magenta R: 255 G: 0 B: 255

		// Delete file from memory
		ilDeleteImages( 1, &imgID );
	}

	// Report error
	if ( !textureLoaded )
	{
		printf( "Unable to load %s\n", path.c_str() );
	}

	return textureLoaded;
}

bool Texture::Load_From_Pixels( GLuint* pixels, GLuint width, GLuint height )
{
	// Free texture if it exists
	Free();

	// Get texture dimensions
	Texture::width = width;
	Texture::height = height;
	Texture::stretchWidth = width;
	Texture::stretchHeight = height;
	
	// Generate texture ID
	glGenTextures( 1, &textureID );

	// Bind texture ID
	glBindTexture( GL_TEXTURE_2D, textureID );

	// Generate texture
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

	// Set texture parameters
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	
	// Unbind texture
	glBindTexture( GL_TEXTURE_2D, NULL );
	
	// Check for error
	GLenum error = glGetError();
	if ( error != GL_NO_ERROR )
	{
		printf( "Error loading texture from %p pixels! %s\n", pixels, gluErrorString( error ) );
		return false;
	}

	return true;
}

void Texture::Free()
{
	// Delete texture
	if ( textureID != 0 )
	{
		glDeleteTextures( 1, &textureID );
		textureID = 0;
	}

	width = 0;
	height = 0;
}

void Texture::Render( Vector2f position, Vector2f origin, float rotation, float scale, SDL_Rect* frameRect )
{
	// If the texture exists
	if ( textureID != 0 )
	{
		// Enable blending
		glEnable( GL_BLEND );

		// Disable Depth Testing
		glDisable( GL_DEPTH_TEST );

		// Start off with clean identity matrix
		glLoadIdentity();

		// Translate object across x/y coordinates
		glTranslatef( position.x, position.y, 0.f );

		// Rotate object in degrees along just Z-axis
		glRotatef( rotation, 0.f, 0.f, 1.f );

		// Translate object across x/y coordinates for rotational offset
		glTranslatef( -origin.x, -origin.y, 0.f );

		// Scale texture on each axes
		glScalef( scale, scale, scale );

		// Bind texture so we can use it
		glBindTexture( GL_TEXTURE_2D, textureID );

		// Allows alpha blending for texture
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		float frameXdivision, frameYdivision;
		float frameX1 = 0, frameX2 = 1, frameY1 = 0, frameY2 = 1;

		// Set up texture coordinates if frame rect included
		if ( frameRect != NULL )
		{
			frameXdivision = float( frameRect->w ) / float( Texture::width );
			frameYdivision = float( frameRect->h ) / float( Texture::height );
			frameX1 = float( frameRect->x ) / float( Texture::width );
			frameX2 = frameX1 + frameXdivision;
			frameY1 = float( frameRect->y ) / float( Texture::height );
			frameY2 = frameY1 + frameYdivision;
		}
		
		glBegin( GL_QUADS );
			// Bottom-left vertex (corner)
			glTexCoord2f( frameX1, frameY1 );
			glVertex2f( 0.f, 0.f );

			// Bottom-right vertex (corner)
			glTexCoord2f( frameX2, frameY1 );
			glVertex2f( (GLfloat)Texture::stretchWidth, 0.f );

			// Top-right vertex (corner)
			glTexCoord2f( frameX2, frameY2 );
			glVertex2f( (GLfloat)Texture::stretchWidth, (GLfloat)Texture::stretchHeight );

			// Top-left vertex (corner)
			glTexCoord2f( frameX1, frameY2 );
			glVertex2f( 0.f, (GLfloat)Texture::stretchHeight );
		glEnd();

		// Disable blending
		glDisable( GL_BLEND );

		// Enable Depth Testing
		glEnable( GL_DEPTH_TEST );

		// Reset texture stretching width/height
		Texture::stretchWidth = Texture::width;
		Texture::stretchHeight = Texture::height;
	}
}

void Texture::Apply_Colorkey( Uint32 colorKey )
{
	int w = Texture::width, h = Texture::height;

	GLuint* pixels = new GLuint[ w * h];

	glBindTexture( GL_TEXTURE_2D, Texture::textureID );
	glGetTexImage( GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );
	
	for ( int y = 0; y < h; y++ )
	{
		for ( int x = 0; x < w; x++ )
		{
			if ( pixels[ x + ( y * w ) ] == colorKey )
			{
				pixels[ x + ( y * w ) ] = 0x000000ff;
			}
		}
	}

	glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

	delete [] pixels;
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

void Texture::Set_Size()
{
	int w, h;

	// Bind Texture
	glBindTexture( GL_TEXTURE_2D, Texture::textureID );

	// Set temporary variable w, h to texture width, height
	glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w );
	glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h );

	Texture::width = w;
	Texture::height = h;
}

GLuint Texture::GetID()
{
	return textureID;
}