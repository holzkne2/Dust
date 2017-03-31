#pragma once
#include "Component.h"
#include "MathF.h"

using namespace MathF;

class Light :
	public Component
{
public:
	Light();
	virtual ~Light();

	virtual void Awake();

	void SetColor(const Color& color) { _color = color; }
	Color GetColor() { return _color; }

	void SetIntensity(float intensity) { _intensity = intensity; }
	float GetIntensity() { return _intensity; }

private:
	Color _color;
	float _intensity;
};

