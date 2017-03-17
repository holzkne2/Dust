#include "Camera.h"
#include "System.h"

Camera::Camera()
{
	_zNear = 0.1;
	_zFar = 1000.0;
	_fov = PI / 2.0;

	_dirty = false;
	_viewport = Matrix4x4::Perspective(_fov,
		(float)System::getInstance().GetGraphics()->GetScreenWidth() / (float)System::getInstance().GetGraphics()->GetScreenHeight(),
		_zNear, _zFar);
}


Camera::~Camera()
{
}

Matrix4x4 Camera::GetViewport()
{
	if (!_dirty)
		return _viewport;
	_dirty = false;
	return _viewport = Matrix4x4::Perspective(_fov,
		(float)System::getInstance().GetGraphics()->GetScreenWidth() / (float)System::getInstance().GetGraphics()->GetScreenHeight(),
		_zNear, _zFar);
}

Matrix4x4 Camera::GetViewMatrix()
{
	return Matrix4x4::Inverse(_gameObject->GetTransform()->GetWorldMatrix());
}