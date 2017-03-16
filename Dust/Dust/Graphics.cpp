#include <iostream>
#include <string>
#include "Graphics.h"

#include <SDL_syswm.h>
#include <Windows.h>

Graphics::Graphics()
{
	_window = 0;
	_renderer = 0;
	_direct3d = 0;

	_screenWidth = 800;
	_screenHeight = 600;

	_fullscreen = false;
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	if (_direct3d)
		delete _direct3d;
}

void Graphics::Awake()
{
	//Setup Window
	_window = SDL_CreateWindow("Dust", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (_fullscreen)
		SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (_window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	//May not be needed
	//Setup Renderer
	//_renderer = SDL_CreateRenderer(_window, SDL_VIDEO_RENDER_D3D11, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//if (_renderer == nullptr){
	//	SDL_DestroyWindow(_window);
	//	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	//	SDL_Quit();
	//}

	//Get HWND
	SDL_SysWMinfo systemInfo;
	SDL_VERSION(&systemInfo.version);
	SDL_GetWindowWMInfo(_window, &systemInfo);

	HWND handle = systemInfo.info.win.window;

	//Setup Direct3D
	_direct3d = new Direct3D();
	_direct3d->Initialize(_screenHeight, _screenHeight, false, handle, _fullscreen, 0.1, 1000);
}

void Graphics::Render()
{
	_direct3d->BeginScene(0.1, 0.1, 0.1);
	//SDL_RenderClear(_renderer);
	//Background Color
	//SDL_SetRenderDrawColor(_renderer, 134, 205, 250, 255);

	//SDL_RenderPresent(_renderer);
	_direct3d->EndScene();
}
