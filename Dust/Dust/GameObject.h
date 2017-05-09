#pragma once
#include <vector>
#include "Object.h"
#include "Transform.h"
#include "Component.h"

class GameObject :
	public Object
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	void SetTransform(Transform* transform) { _transform = *transform; _transform.SetGameObject(this); }
	Transform* GetTransform() { return &_transform; }

	template<typename T> T* GetComponent();
	template<typename T> T* AddComponent();
	Component* AddComponent(Component*);

protected:
	Transform _transform;
	std::vector<Component*> _components;
};

template<typename T> T* GameObject::GetComponent()
{
	T* result;

	for (unsigned int i = 0; i < _components.size(); i++)
	{
		result = dynamic_cast<T*>(_components[i]);
		if (result != NULL)
			return result;
	}

	return nullptr;
}

template<typename T> T* GameObject::AddComponent()
{
	T* add = new T();
	if (dynamic_cast<Component*>(add) == NULL)
	{
		delete add;
		return nullptr;
	}
	static_cast<Component*>(add)->SetGameObject(this);
	_components.push_back(add);
	add->Awake();
	return add;
}