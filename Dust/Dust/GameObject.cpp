#include "GameObject.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

GameObject::GameObject()
{
	_transform.SetGameObject(this);
}


GameObject::~GameObject()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			delete _components[i];
	}
	_components.clear();
}

void GameObject::Update()
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		if (_components[i])
			_components[i]->Update();
	}
}

Component* GameObject::AddComponent(Component* component)
{
	_components.push_back(component);
	component->SetGameObject(this);
	return component;
}