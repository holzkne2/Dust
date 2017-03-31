#include "Light.h"
#include "System.h"

Light::Light()
{
	_color = Color::White;
	_intensity = 1;

	//Awake();
}

Light::~Light()
{
}

void Light::Awake()
{
	System::getInstance().GetScene()->AddLight(this);
}