#pragma once

#include <vector>
#include "GameObject.h"
#include "MeshRenderer.h"
#include "Light.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Update();

	void SampleScene();

	const std::vector<GameObject*>* GetGameObjects() const { return &_gameObjects; }
	const std::vector<MeshRenderer*>* GetMeshRenderers() const { return &_meshRenderers; }
	const std::vector<Light*>* GetLights() const { return &_lights; }

	void AddGameObject(GameObject*);
	void AddMeshRenderer(MeshRenderer*);
	void AddLight(Light*);

private:
	std::vector<GameObject*> _gameObjects;
	std::vector<MeshRenderer*> _meshRenderers;
	std::vector<Light*> _lights;
};

