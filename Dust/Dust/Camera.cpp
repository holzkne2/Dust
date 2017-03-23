#include "Camera.h"
#include "System.h"

Camera::Camera()
{
	_zNear = 0.1;
	_zFar = 1000.0;
	_fov = PI / 2.0;
}

Camera::~Camera()
{
}

Matrix4x4 Camera::GetViewport()
{
	return Matrix4x4::Perspective(_fov,
		(float)Graphics::getInstance().GetScreenWidth() / (float)Graphics::getInstance().GetScreenHeight(),
		_zNear, _zFar);
}

Matrix4x4 Camera::GetViewMatrix()
{
	return Matrix4x4::Inverse(_gameObject->GetTransform()->GetWorldMatrix());
}