#include <iostream>
#include <string>
#include <SDL.h>
#include "res_path.h"
#include "System.h"
#include <memory>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

int main(int argc, char **argv){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	System *system;

	// Create the system object.
	system = &System::getInstance();
	if (!system)
		return 0;

	system->Initialize();

	system->Run();

	unique_ptr<float> test = make_unique<float>(10);

	system->Shutdown();

	return 0;
}