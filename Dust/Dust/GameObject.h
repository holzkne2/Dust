#pragma once
#include <vector>
#include "Object.h"
#include "Transform.h"
#include "Component.h"

#include "Camera.h"
#include "Light.h"
#include "MeshRenderer.h"

class GameObject :
	public Object
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();

	//TODO: Remove Set
	void SetTransform(Transform* transform) { _transform = *transform; _transform.SetGameObject(this); }
	Transform* GetTransform() { return &_transform; }

	template<typename T> T* GetComponent();
	template<typename T> T* AddComponent();
	Component* AddComponent(Component*);

	bool IsEnable() { return _enable; }
	void SetEnable(bool enable) { _enable = enable; }

	virtual void serialize(std::ostream& stream) {
		stream << "GameObject ";
		_transform.serialize(stream);
		stream << "Components ";
		for (unsigned int i = 0; i < _components.size(); i++)
		{
			_components[i]->serialize(stream);
		}
		stream << "ComponentsEND ";
	}
	virtual void deserialize(std::istream& stream) {
		string word;
		stream >> word;
		if (word == "Transform")
			_transform.deserialize(stream);
		do
		{
			stream >> word;
			if (word == "Camera")
			{
				Camera* camera = new Camera();
				camera->deserialize(stream);
				AddComponent(camera);
			}
			else if (word == "Light")
			{
				Light* light = new Light();
				light->deserialize(stream);
				AddComponent(light);
			}
			else if (word == "MeshRenderer")
			{
				MeshRenderer* meshRenderer = new MeshRenderer();
				meshRenderer->deserialize(stream);
				AddComponent(meshRenderer);
			}
		} while (word != "ComponentsEND" || stream.eof());
	}

protected:
	Transform _transform;
	std::vector<Component*> _components;
	bool _enable;
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