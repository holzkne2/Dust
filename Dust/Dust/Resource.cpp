#include "Resource.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

Resource::Resource()
{
	_resourceID = 0;
	_path = L"";
	_resourceID = Resource_Null;
	_isLoaded = false;
}


Resource::~Resource()
{
}
