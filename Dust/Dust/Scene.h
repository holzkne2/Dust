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

	void Save();

	void Load();
	void Unload();

	void Update();

	void SampleScene();

	const std::vector<GameObject*>* GetGameObjects() const { return &_gameObjects; }
	const std::vector<MeshRenderer*>* GetMeshRenderers() const { return &_meshRenderers; }
	const std::vector<Light*>* GetLights() const { return &_lights; }

	void AddGameObject(GameObject*);
	void AddMeshRenderer(MeshRenderer*);
	void AddLight(Light*);

	void SetPath(std::wstring path) { _path = path; }
	std::wstring GetPath() const { return _path; }

	void SetIndex(unsigned long index) { _index = index; }
	unsigned long GetIndex() { return _index; }

	bool IsLoaded() { return _isLoaded; }

private:
	std::vector<GameObject*> _gameObjects;
	std::vector<MeshRenderer*> _meshRenderers;
	std::vector<Light*> _lights;

	//TODO: Is a scene a resources?
	wstring _path;
	unsigned long _index;
	bool _isLoaded;
};

