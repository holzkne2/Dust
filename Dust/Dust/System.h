#pragma once

#include "Graphics.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"

class System
{
public:
	System();
	virtual ~System();

	static System& getInstance()
	{
		static System instance;
		return instance;
	}

	void Initialize();
	void Run();
	void Shutdown();

private:
	Debug* _debug;
	Graphics *_graphics;
	ResourceManager *_resources;
	SceneManager* _sceneManager;
	//Scene *_scene;
};