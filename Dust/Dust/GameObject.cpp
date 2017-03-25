#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			delete _components[i];
	}
}

void GameObject::Update()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			_components[i]->Update();
	}
}