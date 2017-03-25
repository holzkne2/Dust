#pragma once

#include <vector>
#include "GameObject.h"
#include "MeshRenderer.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Update();

	void SampleScene();

	const std::vector<GameObject*>* GetGameObjects() const { return &_gameObjects; }
	const std::vector<MeshRenderer*>* GetMeshRenderers() const { return &_meshRenderers; }

	void AddGameObject(GameObject*);
	void AddMeshRenderer(MeshRenderer*);

private:
	std::vector<GameObject*> _gameObjects;
	std::vector<MeshRenderer*> _meshRenderers;
};

