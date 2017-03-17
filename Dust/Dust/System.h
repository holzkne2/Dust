#pragma once

#include "Graphics.h"
#include "Scene.h"

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

	Graphics* GetGraphics() { return _graphics; }

	void Initialize();
	void Run();
	void Shutdown();

private:
	Graphics *_graphics;
	Scene *_scene;
};

