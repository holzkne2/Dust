#pragma once

#include "GameObject.h"
//#include <vector>

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Awake();
	void Start();
	void Update();

private:
	//std::vector<GameObject> _gameObjects;
};

