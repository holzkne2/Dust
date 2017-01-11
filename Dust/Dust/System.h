#pragma once

#include "Graphics.h"
#include "Scene.h"

class System
{
public:
	System();
	virtual ~System();

	void Initialize();
	void Run();

private:
	Graphics *_graphics;
	Scene *_scene;
};

