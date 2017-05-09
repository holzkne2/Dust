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

private:
	float _zFar;
	float _zNear;
	float _fov;
};

