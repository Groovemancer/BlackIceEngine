#include "Main.h"
#include <algorithm>

std::string Helpers::ToLower( std::string str )
{
	for ( unsigned int i = 0; i < str.length(); i++ )
	{
		if ( str[ i ] >= 0x41 && str[ i ] <= 0x5A )
		{
			str[ i ] = str[ i ] + 0x20;
		}
	}
	return str;
}

std::string Helpers::ToUpper( std::string str )
{
	for ( unsigned int i = 0; i < str.length(); i++ )
	{
		if ( str[ i ] >= 0x61 && str[ i ] <= 0x7A )
		{
			str[ i ] = str[ i ] - 0x20;
		}
	}
	return str;
}

float Helpers::Clampf( float value, float min, float max )
{
	return std::max<float>( std::min<float>( value, max ), min );
}

int Helpers::Clampi( int value, int min, int max )
{
	return std::max<int>( std::min<int>( value, max ), min );
}