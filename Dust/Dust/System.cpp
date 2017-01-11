#include <iostream>
#include <string>
#include "System.h"


System::System()
{
	_graphics = 0;
	_scene = 0;
}

System::~System()
{
	if (_scene)
		delete _scene;
	if (_graphics)
		delete _graphics;

	SDL_Quit();
}

void System::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	_graphics = new Graphics();
	_graphics->Awake();
}

void System::Run()
{
	//Awake GameObjects
	_scene->Awake();
	
	//Start GameObjects
	_scene->Start();
	
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
				/* process other events you want to handle here */
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