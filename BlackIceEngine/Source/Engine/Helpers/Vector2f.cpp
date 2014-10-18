#include "Engine\Main.h"

Vector2f::Vector2f()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2f::Vector2f( float x, float y )
{
	Vector2f::x = x;
	Vector2f::y = y;
}

float Vector2f::Magnitude( Vector2f v1 )
{
	return std::sqrtf( std::powf( v1.x, 2.0f ) + std::powf( v1.y, 2.0f ) );
}

Vector2f Vector2f::Normalized( Vector2f v1)
{
	return Vector2f( v1.x / Magnitude( v1 ), v1.y / Magnitude( v1 ) );
}

float Vector2f::Distance( Vector2f v1, Vector2f v2 )
{
	return std::sqrtf(
		std::powf( v2.x - v1.x, 2.0f ) +
		std::powf( v2.y - v1.y, 2.0f ) );
}

bool Vector2f::IsWithinRange( Vector2f v1, Vector2f v2, float range )
{
	return Distance( v1, v2 ) <= range;
}

void Vector2f::Add( Vector2f v1 )
{
	x += v1.x;
	y += v1.y;
}

Vector2f Vector2f::Add( Vector2f v1, Vector2f v2 )
{
	return Vector2f( v1.x + v2.x, v1.y + v2.y );
}

void Vector2f::Subtract( Vector2f v1)
{
	x -= v1.x;
	y -= v1.y;
}
	
Vector2f Vector2f::Subtract( Vector2f v1, Vector2f v2 )
{
	return Vector2f( v1.x - v2.x, v1.y - v2.y );
}
	
void Vector2f::Multiply( Vector2f v1 )
{
	x *= v1.x;
	y *= v1.y;
}
	
Vector2f Vector2f::Multiply( Vector2f v1, Vector2f v2 )
{
	return Vector2f( v1.x * v2.x, v1.y * v2.y );
}
	
void Vector2f::Multiply( float scalar )
{
	x *= scalar;
	y *= scalar;
}
	
Vector2f Vector2f::Multiply( Vector2f v1, float scalar )
{
	return Vector2f( v1.x * scalar, v1.y * scalar );
}
	
float Vector2f::Dot( Vector2f v1)
{
	return (x * v1.x) + (y * v1.y);
}
	
float Vector2f::Dot( Vector2f v1, Vector2f v2 )
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

Vector2f& Vector2f::operator +=(const Vector2f& v)
{
    x += v.x;
    y += v.y;
    return (*this);
}
        
Vector2f& Vector2f::operator -=(const Vector2f& v)
{
    x -= v.x;
    y -= v.y;
    return (*this);
}
        
Vector2f& Vector2f::operator *=(float t)
{
    x *= t;
    y *= t;
    return (*this);
}
        
Vector2f& Vector2f::operator /=(float t)
{
    float f = 1.0f / t;
    x *= f;
    y *= f;
    return (*this);
}
        
Vector2f& Vector2f::operator *=(const Vector2f& v)
{
    x *= v.x;
    y *= v.y;
    return (*this);
}
        
Vector2f Vector2f::operator -(void) const
{
    return Vector2f( -x, -y );
}
        
Vector2f Vector2f::operator +(const Vector2f& v) const
{
    return Vector2f( x + v.x, y + v.y );
}

Vector2f Vector2f::operator -(const Vector2f& v) const
{
    return Vector2f( x - v.x, y - v.y );
}
        
Vector2f Vector2f::operator *(float t) const
{
    return Vector2f( x * t, y * t );
}
        
Vector2f Vector2f::operator /(float t) const
{
    float f = 1.0F / t;
    return Vector2f( x * f, y * f );
}
        
float Vector2f::operator *(const Vector2f& v) const
{
    return (x * v.x + y * v.y);
}

bool Vector2f::operator ==(const Vector2f& v) const
{
	return ((x == v.x) && (y == v.y));
}

bool Vector2f::operator !=(const Vector2f& v) const
{
	return ((x != v.x) || (y != v.y));
}

float Vector2f::operator &(void) const
{
    return Vector2f::Magnitude( Vector2f( x, y ) );
}

Vector2f Vector2f::operator !(void) const
{
	return Vector2f::Normalized( Vector2f( x, y ) );
}