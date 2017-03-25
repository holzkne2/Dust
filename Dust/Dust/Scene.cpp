#include "Scene.h"
#include "UnlitColorShader.h"
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

void Scene::Update()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->Update();
	}
}

void Scene::SampleScene()
{
	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();
	AddGameObject(camera);
	
	//TODO:Better Shader Handlers
	UnlitColorShader* unlitColorShader = new UnlitColorShader();

	GameObject* simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, 0, -5));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->GetSharedMesh()->CubeTest();
	simpleMesh->GetComponent<MeshRenderer>()->SetShader(unlitColorShader);
	AddGameObject(simpleMesh);

	//simpleMesh = new GameObject();
	//simpleMesh->GetTransform()->SetPosition(Vector3(0, 0, 5));
	//simpleMesh->AddComponent<MeshRenderer>();
	//simpleMesh->GetComponent<MeshRenderer>()->GetSharedMesh()->CubeTest();
	//simpleMesh->GetComponent<MeshRenderer>()->SetShader(unlitColorShader);
	//AddGameObject(simpleMesh);
}

void Scene::AddGameObject(GameObject* gameObject)
{
	_gameObjects.push_back(gameObject);
}

void Scene::AddMeshRenderer(MeshRenderer* meshRenderer)
{
	_meshRenderers.push_back(meshRenderer);
}