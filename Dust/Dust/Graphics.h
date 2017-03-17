#pragma once

#include <SDL.h>
#include "Direct3D.h"
#include "Camera.h"

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();

	void Awake();
	void Render();

	int GetScreenWidth() { return _screenWidth; }
	int GetScreenHeight() { return _screenHeight; }

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	Direct3D *_direct3d;

	int _screenWidth;
	int _screenHeight;

	bool _fullscreen;
};

