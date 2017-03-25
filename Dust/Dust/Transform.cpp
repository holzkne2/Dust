#include "Transform.h"


Transform::Transform()
{
	_position = Vector3::Zero;
	_rotation = Quaternion::Identity;
	_scale = Vector3::One;

	_dirty = false;
	_worldMatrix = Matrix4x4::Identity;

	Awake();
}


Transform::~Transform()
{
}

Matrix4x4 Transform::GetWorldMatrix()
{
	if (!_dirty)
		return _worldMatrix;
	_dirty = false;
	return _worldMatrix = Matrix4x4::TRS(_position, _rotation, _scale);
}