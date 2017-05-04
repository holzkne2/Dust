#include "Scene.h"
#include "Camera.h"
#include "ResourceManager.h"

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
	_lights = std::vector<Light*>();
}

Scene::~Scene()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		delete _gameObjects[i];
	}
	_gameObjects.clear();

	_meshRenderers.clear();

	_lights.clear();
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
	//Create Main Camera
	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();
	AddGameObject(camera);
	
	//Create Light Source
	GameObject* light = new GameObject();
	light->AddComponent<Light>();
	AddGameObject(light);

	//Create Object(s)

	Material* mat = static_cast<Material*>(ResourceManager::getInstance().GetResource(3));
	Mesh* mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(5));

	GameObject* simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, -2, -5));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(45, 15, 45)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(mat);
	AddGameObject(simpleMesh);

	simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, 0, -5));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(15, 15, 15)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(mat);
	AddGameObject(simpleMesh);

	simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, 2, -5));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(-45, 15, -45)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(mat);
	AddGameObject(simpleMesh);
}

void Scene::AddGameObject(GameObject* gameObject)
{
	_gameObjects.push_back(gameObject);
}

void Scene::AddMeshRenderer(MeshRenderer* meshRenderer)
{
	_meshRenderers.push_back(meshRenderer);
}

void Scene::AddLight(Light* light)
{
	_lights.push_back(light);
}