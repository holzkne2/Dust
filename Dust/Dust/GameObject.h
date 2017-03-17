#pragma once
#include <vector>
#include "Object.h"
#include "Transform.h"

class GameObject :
	public Object
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Awake();
	virtual void Start();
	virtual void Update();

	Transform* GetTransform() { return &_transform; }

	template<typename T> T* GetComponent();
	template<typename T> T* AddComponent();

protected:
	Transform _transform;
	std::vector<Component*> _components;
};

template<typename T> T* GameObject::GetComponent()
{
	T* result;

	for (unsigned int i = 0; i < components.size(); i++)
	{
		result = dynamic_cast<T*>(components[i]);
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
	components.push_back(add);
	return add;
}