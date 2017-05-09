#include "SceneManager.h"


SceneManager::SceneManager()
{
	_currentScene = 0;

	Awake();
}


SceneManager::~SceneManager()
{
}

void SceneManager::Awake()
{
}

void SceneManager::ShutDown()
{
	for (auto itr = _scenes.begin(); itr != _scenes.end(); ++itr)
	{
		if (itr->second->IsLoaded())
			itr->second->Unload();
		delete itr->second;
	}
	_scenes.clear();
}

void SceneManager::SetCurrentScene(unsigned long scene)
{
	Scene* curr = GetCurrentScene();
	//TODO: Dont unload things that need to be loaded in new scene if possible
	if (curr->IsLoaded())
		curr->Unload();
	_currentScene = scene;
	curr = GetScene(_currentScene);
	if (!curr->IsLoaded())
		curr->Load();
}

//Does not load scene
Scene* SceneManager::GetCurrentScene()
{
	return GetScene(_currentScene);
}

void SceneManager::AddScene(unsigned long index, Scene* scene)
{
	_scenes.insert(pair<unsigned long, Scene*>(index, scene));
}

Scene* SceneManager::GetScene(unsigned long id)
{
	Scene* s = 0;
	s = _scenes.find(id)->second;
	//TODO: If did not find
	return s;
}