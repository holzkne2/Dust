#include "Debug.h"
#include <iostream>
#include <windows.h>
#include "GameObject.h"
#include "Texture2D.h"
#include "UIImage.h"
#include "SceneManager.h"

Debug::Debug()
{
	_sampleUIImage = 0;
}

Debug::~Debug()
{
}

void Debug::Message(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << "Message: " << msg << std::endl;
}

void Debug::Warning(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Warning: " << msg << std::endl;
}

void Debug::Error(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Error: " << msg << std::endl;
}

void Debug::CreateDebugUI()
{
	GameObject* object = new GameObject();
	_sampleUIImage = object;
	object->GetTransform()->SetPosition(Vector3(-640, 247, -1));
	UIImage* ui_image = object->AddComponent<UIImage>();
	ui_image->SetTexture(static_cast<Texture2D*>(ResourceManager::getInstance().GetResource(13)));
	SceneManager::getInstance().GetCurrentScene()->AddGameObject(object);
}