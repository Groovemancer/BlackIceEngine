#include "Camera.h"
#include "Helpers.h"
//#include "TileEngine.h"
//#include "TileMap.h"


Vector2f Camera::screenOffset = Vector2f( 6, 26 );

Camera::Camera()
{
	position = Vector2f::Zero();
	speed = 1.0f;
}

Camera::Camera( Vector2f position, float speed )
{
	Camera::position = position;
	Camera::speed = speed;
}

void Camera::LockCamera()
{
	// TODO: Add Tile Engine support for Camera
	/*
	position.x = Helpers::Clamp( position.x, 0, TileMap::WidthInPixels() - TileEngine::ViewPortWidth() + screenOffset.x );
	position.y = Helpers::Clamp( position.y, 0, TileMap::HeightInPixels() - TileEngine::ViewPortHeight() + screenOffset.y );
	*/
}