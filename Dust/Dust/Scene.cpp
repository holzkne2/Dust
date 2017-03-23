#include "Scene.h"

#include "Camera.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

Scene::Scene()
{
	_gameObjects = std::vector<GameObject*>();
	_meshRenderers = std::vector<MeshRenderer*>();

	//TESTCODE
	SampleScene();
}

Scene::~Scene()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		delete _gameObjects[i];
	}
	_gameObjects.clear();
	_meshRenderers.clear();
}

void Scene::Awake()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->Awake();
	}
}

void Scene::Start()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->Start();
	}
}

void Scene::Update()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->Update();
	}
}

void Scene::SampleScene()
{
	//TODO: gameobject auto add to list
	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();
	_gameObjects.push_back(camera);
}