#include <iostream>
#include <string>
#include "System.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

System::System()
{
	_graphics = 0;
	_resources = 0;
	_scene = 0;
}

System::~System()
{
}

void System::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	_graphics = &Graphics::getInstance();

	_resources = &ResourceManager::getInstance();
}

void System::Run()
{
	_scene = new Scene();
	
	//TESTCODE
	_scene->SampleScene();

	SDL_Event evt;
	bool programrunning = true;
	while (programrunning)
	{
		// keep looping and processing events here until there are no more events to process
		while (SDL_PollEvent(&evt))
		{
			switch (evt.type)
			{
			case SDL_QUIT:  programrunning = false;   break;
			}
		}
		//Input

		//Time

		//Update GameObjects
		_scene->Update();

		//Physics

		//Graphics
		_graphics->Render();
	}
}

void System::Shutdown()
{
	if (_scene)
		delete _scene;
	if (_resources)
		_resources->ShutDown();
	if (_graphics)
		_graphics->ShutDown();

	SDL_Quit();
}