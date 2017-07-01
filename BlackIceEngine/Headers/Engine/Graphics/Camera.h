#pragma once

#include "Engine\Helpers\Vector2f.h"

class Camera
{
public:
	Vector2f position;
	Vector2f velocity;
	float speed;
	static Vector2f screenOffset;

	Camera();
	Camera( Vector2f position, float speed );
	void LockCamera();
};