#include <iostream>
#include <string>
#include <vector>
#include "Graphics.h"
#include "System.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Light.h"

#include <SDL_syswm.h>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

Graphics::Graphics()
{
	_window = 0;
	_direct3d = 0;

	_screenWidth = 800;
	_screenHeight = 600;

	_fullscreen = false;

	_ambient = Color(0.1, 0.1, 0.1);

	Awake();
}

Graphics::~Graphics()
{
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

	//Get HWND
	SDL_SysWMinfo systemInfo;
	SDL_VERSION(&systemInfo.version);
	SDL_GetWindowWMInfo(_window, &systemInfo);

	_hwnd = &systemInfo.info.win.window;

	//Setup Direct3D
	_direct3d = new Direct3D();
	_direct3d->Initialize(_screenHeight, _screenHeight, false, *_hwnd, _fullscreen, 0.1, 1000);
}

void Graphics::Render()
{
	Matrix4x4 viewMatrix, projectionMatrix, worldMatrix;
	Camera* camera = 0;
	const std::vector<GameObject*>* gameObjects = System::getInstance().GetScene()->GetGameObjects();
	const std::vector<MeshRenderer*>* meshRenderers = System::getInstance().GetScene()->GetMeshRenderers();
	const std::vector<Light*>* lights = System::getInstance().GetScene()->GetLights();
	MeshRenderer* meshRendererPointer = 0;
	Light* lightPointer = 0;
	
	//Clear Buffer
	_direct3d->BeginScene(0.1, 0.1, 0.1);

	//Find Camera
	for (unsigned int i = 0; i < gameObjects->size(); ++i)
	{
		if (gameObjects->at(i)->GetComponent<Camera>() != nullptr)
		{
			camera = gameObjects->at(i)->GetComponent<Camera>();
			continue;
		}
	}

	//Render Camera
	if (camera)
	{
		viewMatrix = camera->GetViewMatrix();
		projectionMatrix = camera->GetViewport();

		unsigned int l = 0;
		do
		{
			if (lights->size() > 0)
				lightPointer = lights->at(l);

			for (unsigned int i = 0; i < meshRenderers->size(); ++i)
			{
				meshRendererPointer = meshRenderers->at(i);
				worldMatrix = meshRendererPointer->GetGameObject()->GetTransform()->GetWorldMatrix();

				if (!meshRendererPointer->GetSharedMesh()->IsInitizlized())
					if (!meshRendererPointer->GetSharedMesh()->Initialize(_direct3d->GetDevice()))
						std::cout << "Mesh Initialize Failed" << std::endl;
				meshRendererPointer->GetSharedMesh()->Render(_direct3d->GetDeviceContext());

				meshRendererPointer->GetSharedMaterial()->Render(_direct3d->GetDeviceContext(),
					meshRendererPointer->GetSharedMesh()->GetIndexCount(),
					worldMatrix, viewMatrix, projectionMatrix, lightPointer, _ambient);

				/*if (!meshRendererPointer->GetShader()->IsInitizlized())
					if (!meshRendererPointer->GetShader()->Initialize(_direct3d->GetDevice(), *_hwnd))
						std::cout << "Shader Initialize Failed" << std::endl;
				meshRendererPointer->GetShader()->Render(_direct3d->GetDeviceContext(),
					meshRendererPointer->GetSharedMesh()->GetIndexCount(),
					worldMatrix, viewMatrix, projectionMatrix, lightPointer, _ambient);*/
			}

			++l;
		} while (l < lights->size());
	}

	//Swap Buffer
	_direct3d->EndScene();
}

void Graphics::ShutDown()
{
	SDL_DestroyWindow(_window);
	if (_direct3d)
		delete _direct3d;

}