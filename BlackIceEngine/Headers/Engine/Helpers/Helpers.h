#ifndef INC_HELPERS_H
#define INC_HEPLERS_H

#include <SDL.h>
#include <string>

class Helpers
{
public:
	static std::string ToLower( std::string str );
	static std::string ToUpper( std::string str );
	static float Clampf( float value, float min, float max );
	static int Clampi( int value, int min, int max );
};

#endif /* INC_HELPERS_H */