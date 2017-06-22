#pragma once
#include "Object.h"
#include <string>
#include "Debug.h"
#include "FileHelperDust.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

typedef enum
{
	Resource_Null = 0,
	Resource_Mesh = 1,
	Resource_Material = 2,
	Resource_Texture = 3,
	Resource_Font = 4
} ResourceType;

class Resource :
	public Object
{
public:
	Resource();
	virtual ~Resource();

	virtual void Load() = 0;
	virtual void Unload() = 0;

	void SetResourceID(unsigned long resourceID) { _resourceID = resourceID; }
	unsigned long GetResourceID() { return _resourceID; }

	void SetPath(std::wstring path) { _path = path; }
	std::wstring GetPath() const { return _path; }

	void SetType(ResourceType type) { _type = type; }
	ResourceType GetType() { return _type; }

	bool IsLoaded() { return _isLoaded; }

protected:
	unsigned long _resourceID;
	std::wstring _path;
	ResourceType _type;
	bool _isLoaded;
};

