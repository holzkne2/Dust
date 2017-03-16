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

void GameObject::Awake()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			_components[i]->Awake();
	}
}

void GameObject::Start()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			_components[i]->Start();
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