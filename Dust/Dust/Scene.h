#pragma once

#include <vector>
#include "GameObject.h"
#include "MeshRenderer.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Awake();
	void Start();
	void Update();

	void SampleScene();

	std::vector<GameObject*>* GetGameObjects() { return &_gameObjects; }
	std::vector<MeshRenderer*>* GetMeshRenderers() { return &_meshRenderers; }

private:
	std::vector<GameObject*> _gameObjects;
	std::vector<MeshRenderer*> _meshRenderers;
};

