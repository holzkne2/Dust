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

	virtual void serialize(std::ostream& stream) {
		stream << "Light ";
		stream << "Color " << _color << "Intensity " << _intensity << " ";
	}
	virtual void deserialize(std::istream& stream) {
		string word;
		stream >> word;
		if (word == "Color")
			stream >> _color;
		stream >> word;
		if (word == "Intensity")
			stream >> _intensity;
	}

private:
	Color _color;
	float _intensity;
};

