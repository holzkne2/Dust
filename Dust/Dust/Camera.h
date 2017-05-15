#pragma once
#include "Component.h"
#include "MathF.h"

using namespace MathF;

class Camera :
	public Component
{
public:
	Camera();
	virtual ~Camera();

	virtual void Awake() {}

	Matrix4x4 GetViewport();
	Matrix4x4 GetViewMatrix();

	void SetFar(float zFar) { _zFar = zFar; }
	void SetNear(float zNear) { _zNear = zNear; }
	void SetFov(float fov) { _fov = fov; }

	virtual void serialize(std::ostream& stream) {
		stream << "Camera ";
		stream << "ZFar " << _zFar << " ZNear " << _zNear << " FOV " << _fov << " ";
	}
	virtual void deserialize(std::istream& stream) {
		string word;
		stream >> word;
		if (word == "ZFar")
			stream >> _zFar;
		stream >> word;
		if (word == "ZNear")
			stream >> _zNear;
		stream >> word;
		if (word == "FOV")
			stream >> _fov;
	}

private:
	float _zFar;
	float _zNear;
	float _fov;
};

