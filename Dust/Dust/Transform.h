#pragma once
#include "MathF.h"
#include "Component.h"

using namespace MathF;

class Transform :
	public Component
{
public:
	Transform();
	virtual ~Transform();

	virtual void Awake() {}

	void SetPosition(const Vector3& position) { _dirty = true; _position = position; }
	Vector3 GetPosition() { return _position; }

	void SetRotation(const Quaternion& rotation) { _dirty = true; _rotation = rotation; }
	Quaternion GetRotation() { return _rotation; }

	void SetScale(const Vector3& scale) { _dirty = true; _scale = scale; }
	Vector3 GetScale() { return _scale; }

	void Translate(const Vector3& translation) { _dirty = true; _position += translation; }
	
	Matrix4x4 GetWorldMatrix();

private:
	Vector3 _position;
	Quaternion _rotation;
	Vector3 _scale;

	bool _dirty;
	Matrix4x4 _worldMatrix;
};

