#pragma once
#include "Resource.h"
#include <map>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	void Awake();
	void ShutDown();

private:
	void FindResources(std::string);

private:
	std::map<unsigned long, Resource*> _resources;
};

