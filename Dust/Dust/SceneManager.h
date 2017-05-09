#pragma once
#include <map>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	static SceneManager& getInstance()
	{
		static SceneManager instance;
		return instance;
	}

	void Awake();
	void ShutDown();

	void SetCurrentScene(unsigned long);
	Scene* GetCurrentScene();

	void AddScene(unsigned long, Scene*);

private:
	Scene* GetScene(unsigned long);

private:
	unsigned long _currentScene;
	std::map<unsigned long, Scene*> _scenes;
};

