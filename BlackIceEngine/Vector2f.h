#ifndef INC_VECTOR2F_H
#define INC_VECTOR2F_H

class Vector2f
{
public:
	// Members
	float x;
	float y;

	// Functions
	Vector2f();
	Vector2f( float x, float y );

	static Vector2f Down()	{ return Vector2f( 0.0f, 1.0f ); }
	static Vector2f Left()	{ return Vector2f(-1.0f, 0.0f ); }
	static Vector2f Right() { return Vector2f( 1.0f, 0.0f ); }
	static Vector2f Up()	{ return Vector2f( 0.0f, -1.0f); }
	
	static Vector2f One()	{ return Vector2f( 1.0f, 1.0f ); }
	static Vector2f UnitX() { return Vector2f( 1.0f, 0.0f ); }
	static Vector2f UnitY() { return Vector2f( 0.0f, 1.0f ); }
	static Vector2f Zero()	{ return Vector2f( 0.0f, 0.0f ); }

	static float Magnitude( Vector2f v1 );
	static Vector2f Normalized( Vector2f v1);
	static float Distance( Vector2f v1, Vector2f v2 );
	static bool IsWithinRange( Vector2f v1, Vector2f v2, float range );

	static Vector2f Add( Vector2f v1, Vector2f v2 );
	void Add( Vector2f v1 );	

	void Subtract( Vector2f v1);
	static Vector2f Subtract( Vector2f v1, Vector2f v2 );
	
	void Multiply( Vector2f v1 );	
	static Vector2f Multiply( Vector2f v1, Vector2f v2 );	
	void Multiply( float scalar );	
	static Vector2f Multiply( Vector2f v1, float scalar );
	
	float Dot( Vector2f v1);	
	static float Dot( Vector2f v1, Vector2f v2 );

	Vector2f& operator +=(const Vector2f& v);        
	Vector2f& operator -=(const Vector2f& v);
	Vector2f& operator *=(float t);
	Vector2f& operator /=(float t);
	Vector2f& operator *=(const Vector2f& v);
	Vector2f operator -(void) const;
	Vector2f operator +(const Vector2f& v) const;
	Vector2f operator -(const Vector2f& v) const;
	Vector2f operator *(float t) const;
	Vector2f operator /(float t) const;
	float operator *(const Vector2f& v) const;
	bool operator ==(const Vector2f& v) const;
	bool operator !=(const Vector2f& v) const;
	float operator &(void) const; // Returns Magnitude
	Vector2f operator !(void) const; // Returns Normalized
};

#endif /* INC_VECTOR2F_H */