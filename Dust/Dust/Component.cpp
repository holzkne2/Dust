#include "Component.h"
#include "GameObject.h"

Component::Component()
{
	_gameObject = 0;
	_enable = true;
}


Component::~Component()
{
}

bool Component::IsEnable()
{
	return _gameObject->IsEnable() ? _enable : false;
}