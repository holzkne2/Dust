#pragma once
#include "Object.h"

class GameObject;

class Component :
	public Object
{
public:
	Component();
	virtual ~Component();

	//TODO: doesnt have to be absract
	virtual void Awake() = 0;
	virtual void Update() {}

	//TODO: Edit Gameobject's component list / Make Less Hackable
	void SetGameObject(GameObject* gameObject) { _gameObject = gameObject; }
	GameObject* GetGameObject() { return _gameObject; }

	virtual void serialize(std::ostream& stream) {}
	virtual void deserialize(std::istream& stream) {}

protected:
	GameObject* _gameObject;
};

