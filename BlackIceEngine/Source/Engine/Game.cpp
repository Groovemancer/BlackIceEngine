#include "Engine\Main.h"

Camera Game::camera;
ScreenManager Game::screenManager;
int Game::screenWidth;
int Game::screenHeight;

bool Game::Initialize()
{
	// Initialization flag
	bool success = true;

	// Get some initial data from the config file
	if ( Game::ReadConfigFile() == false )
	{
		success = false;
	}

	// Initialize SDL
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		// Use OpenGL 2.1
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

		// Create window
		window = SDL_CreateWindow( "BlackIceEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if ( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			// Create context
			context = SDL_GL_CreateContext( window );
			if ( context == NULL )
			{
				printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
			}

			// Initialize OpenGL
			if ( !Init_GL() )
			{
				printf( "Unable to initialize OpenGL!\n" );
				success = false;
			}
		}
	}

	return success;
}

bool Game::Init_GL()
{
	bool success = true;
	GLenum error = GL_NO_ERROR;

	// Set the viewport
	glViewport( 0.f, 0.f, screenWidth, screenHeight );

	// Initialize Projection Matrix
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, screenWidth, screenHeight, 0.0, 1.0, -1.0 );

	// Check for error
	if ( error != GL_NO_ERROR )
	{
		printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
		success = false;
	}

	// Initialize Modelview Matrix
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	// Check for error
	if ( error != GL_NO_ERROR )
	{
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }

	// Initialize clear color
	glClearColor( 0.f, 0.f, 0.f, 1.f );

	// Check for error
	if ( error != GL_NO_ERROR )
	{
		printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
		success = false;
	}

	// Enable texturing
	glEnable( GL_TEXTURE_2D );

	// Check for error
	if ( error != GL_NO_ERROR )
	{
		printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
		success = false;
	}

	// Initialize DevIL
	ilInit();
	ilClearColor( 255, 255, 255, 0 );

	// Check for error
	ILenum ilError = ilGetError();
	if ( ilError != IL_NO_ERROR )
	{
		printf( "Error initializing DevIL! %s\n", iluErrorString( ilError) );
		success = false;
	}
	
	return success;
}

void Game::Set_Window_Title( std::string title )
{
	SDL_SetWindowTitle( window, title.c_str() );
}

void Game::Clean_Up()
{
	//Destroy window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::Clear_Screen( SDL_Color color )
{
	// Normally we use color values between 0 - 1.0
	// We divide each color by 255, what SDL_Color uses, for each color to get a value between 0 - 1.0
	Game::Clear_Screen( color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, 255 );
}

void Game::Clear_Screen( float r, float g, float b, float a )
{
	// Clear the screen
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Fills screen with color
	glClearColor( r, g, b, a );
}

void Game::Update_Screen()
{
	// Update screen
	SDL_GL_SwapWindow( window );
}

bool Game::ReadConfigFile()
{
	// Set default dimensions, in case reading/writing to/from a config file doesn't work
	screenWidth = 800;
	screenHeight = 600;
	try
	{
		std::ifstream input( "config.ini" );
		if ( !input.is_open() )
		{
			// Config.ini does not exist so create one
			INIFile config( "config.ini", true, false );
			config[ "Display" ][ "screenWidth" ] = "800";
			config[ "Display" ][ "screenHeight" ] = "600";
			screenWidth = 800;
			screenHeight = 600;
		}
		else
		{
			// Config.ini does exist so read from it
			INIFile config( "config.ini", true, true );
			screenWidth = atoi( config[ "Display" ][ "screenWidth" ].c_str() );
			screenHeight = atoi( config[ "Display" ][ "screenHeight" ].c_str() );
		}
		return true;
	}
	catch ( char* str )
	{
		std::cout << "Exception raised: " << str << "\n";
		return false;
	}
}

int Game::GetWidth()
{
	return screenWidth;
}

int Game::GetHeight()
{
	return screenHeight;
}