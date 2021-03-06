#pragma once

#include <SDL.h>
#include "Direct3D.h"

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();

	static Graphics& getInstance()
	{
		static Graphics instance;
		return instance;
	}

	void Awake();
	void Render();
	void ShutDown();

	int GetScreenWidth() { return _screenWidth; }
	int GetScreenHeight() { return _screenHeight; }

	void SetAmbient(Color color) { _ambient = color; }
	Color GetAmbient() { return _ambient; }

	Direct3D* const GetDirect3D() { return _direct3d; }

	HWND* const GetHWND() { return _hwnd; }

private:
	SDL_Window *_window;
	Direct3D *_direct3d;
	HWND* _hwnd;

	int _screenWidth;
	int _screenHeight;

	bool _fullscreen;

	Color _ambient;
};

