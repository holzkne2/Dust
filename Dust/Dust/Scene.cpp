#include "Scene.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "Graphics.h"

#include <fstream>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using namespace std;

Scene::Scene()
{
	_gameObjects = std::vector<GameObject*>();
	_meshRenderers = std::vector<MeshRenderer*>();
	_lights = std::vector<Light*>();

	_path = L"";
	_isLoaded = false;
}

Scene::~Scene()
{
	Unload();
}

void Scene::Save()
{
	std::filebuf file;
	file.open("TestScene", ios::out);
	ostream os(&file);
	
	os << "Ambient ";
	os << Graphics::getInstance().GetAmbient();
	
	os << "GameObjects ";
	//os << "GameObject ";
	//_gameObjects[_gameObjects.size() - 1]->serialize(os);
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->serialize(os);
	}
	os << "GameObjectsEND ";
	
	file.close();
}

void Scene::Load()
{
	string word;
	//_isLoaded = true;
	//return;

	std::filebuf file;
	file.open("TestScene", ios::in);
	istream is(&file);
	
	//Ambient
	is >> word;
	Color ambient;
	is >> ambient;
	Graphics::getInstance().SetAmbient(ambient);
	
	//GAMEOBJECTS word
	is >> word;
	while (is >> word)
	{
		if (word == "GameObject")
		{
			GameObject* gameObject = new GameObject();
			gameObject->deserialize(is);
			AddGameObject(gameObject);
		}
		else if (word == "GameObjectsEND")
			break;
	}

	file.close();
	_isLoaded = true;
	return;

	/*
	map<int, Object*> objects = map<int, Object*>();
	//TODO: Remove
	map<int, int> id_token = map<int, int>();
	vector<string> tokens = GetTokensFromFile(wstos(_path));

	Object* object;
	//Get Settings
	//Get <ID, Token> pair and Create Objects
	int i = 0;
	while (i < tokens.size())
	{
		if (tokens[i] == "_ambient:")
		{
			Color ambient = Color(stof(tokens[1 + i]), stof(tokens[2 + i]),
				stof(tokens[3 + i]), stof(tokens[4 + i]));
			Graphics::getInstance().SetAmbient(ambient);
			i += 5;
		}
		else if (tokens[i] == "---" && tokens[1 + i] == "id")
		{
			i += 2;
			int curr_id = stoi(tokens[i]);
			id_token.insert(pair<int, int>(curr_id, ++i));
			if (tokens[i] == "GameObject:")
			{
				object = new GameObject();
			}
			else if (tokens[i] == "Transform:")
			{
				object = new Transform();
			}
			else if (tokens[i] == "Camera:")
			{
				object = new Camera();
			}
			objects.insert(pair<int, Object*>(curr_id, object));
			++i;
			
		}
		else
			++i;
	}

	//Add to GameObjects to Scene
	//Link Objects
	i = 0;
	while (i < tokens.size())
	{
		if (tokens[i] == "---" && tokens[1 + i] == "id")
		{
			i += 2;
			int curr_id = stoi(tokens[i]);
			++i;
			if (tokens[i] == "GameObject:")
			{
				GameObject* gameObject = static_cast<GameObject*>(objects.find(curr_id)->second);
				AddGameObject(gameObject);
				++i;
				while (i < tokens.size() && tokens[i].at(0) == '\t')
				{
					// Linking Auto Done Below
					
					if (tokens[i] == "\t_transform:")
					{
						gameObject->SetTransform(static_cast<Transform*>(objects.find(stoi(tokens[1+i]))->second));
						i += 2;
					}
					else if (tokens[i] == "\t_components:")
					{
						++i;
						while (i < tokens.size() && tokens[i] == "\t-")
					{
					gameObject->AddComponent(static_cast<Component*>(objects.find(stoi(tokens[2+i]))->second));
						i += 3;
					}
					else
						++i;
					
					++i;
				}
			}
			else if (tokens[i] == "Transform:")
			{
				Transform* transform = static_cast<Transform*>(objects.find(curr_id)->second);
				++i;
				while (i < tokens.size() && tokens[i].at(0) == '\t')
				{
					if (tokens[i] == "\t_position:")
					{
						transform->SetPosition(Vector3(stof(tokens[i + 1]), stof(tokens[i + 2]), stof(tokens[i + 3])));
						i += 4;
					}
					if (tokens[i] == "\t_rotation:")
					{
						transform->SetRotation(Quaternion(stof(tokens[i + 1]), stof(tokens[i + 2]), stof(tokens[i + 3]), stof(tokens[i + 4])));
						i += 5;
					}
					if (tokens[i] == "\t_scale:")
					{
						transform->SetScale(Vector3(stof(tokens[i + 1]), stof(tokens[i + 2]), stof(tokens[i + 3])));
						i += 4;
					}
					// !Must be done Last!
					if (tokens[i] == "\t_gameObject:")
					{
						static_cast<GameObject*>(objects.find(stoi(tokens[i + 1]))->second)->SetTransform(transform);
						i += 2;
					}
					else
						++i;
				}
			}
			else if (tokens[i] == "Camera:")
			{
				Camera* camera = static_cast<Camera*>(objects.find(curr_id)->second);
				++i;
				while (i < tokens.size() && tokens[i].at(0) == '\t')
				{
					if (tokens[i] == "\t_zFar:")
					{
						camera->SetFar(stof(tokens[i + 1]));
						i += 2;
					}
					if (tokens[i] == "\t_zNear:")
					{
						camera->SetNear(stof(tokens[i + 1]));
						i += 2;
					}
					if (tokens[i] == "\t_fov:")
					{
						camera->SetFov(stof(tokens[i + 1]));
						i += 2;
					}
					if (tokens[i] == "\t_gameObject:")
					{
						static_cast<GameObject*>(objects.find(stoi(tokens[i + 1]))->second)->AddComponent(camera);
						i += 2;
					}
					else
						++i;
				}
			}
			else
				++i;
		}
		else
			++i;
	}

	_isLoaded = true;*/
}

void Scene::Unload()
{
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		delete _gameObjects[i];
	}
	_gameObjects.clear();

	_meshRenderers.clear();

	_lights.clear();

	_isLoaded = false;
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
	Material* umat = static_cast<Material*>(ResourceManager::getInstance().GetResource(4));


	Mesh* cube_mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(5));
	Mesh* sphere_mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(6));
	Mesh* cone_mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(7));
	Mesh* terrain_mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(9));

	GameObject* simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, -5, -10));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(0, 0, 0)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(terrain_mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(mat);
	AddGameObject(simpleMesh);

	simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, 0, -5));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(0, 0, 0)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(sphere_mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(mat);
	AddGameObject(simpleMesh);

	simpleMesh = new GameObject();
	simpleMesh->GetTransform()->SetPosition(Vector3(0, 2, -5));
	simpleMesh->GetTransform()->SetRotation(Quaternion::Euler(Vector3(15, 7, 23)));
	simpleMesh->AddComponent<MeshRenderer>();
	simpleMesh->GetComponent<MeshRenderer>()->SetSharedMesh(cone_mesh);
	simpleMesh->GetComponent<MeshRenderer>()->SetMaterial(umat);
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