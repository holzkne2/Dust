#include "Debug.h"
#include <iostream>
#include <windows.h>
#include "GameObject.h"
#include "Texture2D.h"
#include "UIImage.h"
#include "UIText.h"
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
	object->GetTransform()->SetPosition(Vector3(-640, 119, -1));
	UIImage* ui_image = object->AddComponent<UIImage>();
	ui_image->SetTexture(static_cast<Texture2D*>(ResourceManager::getInstance().GetResource(13)));
	SceneManager::getInstance().GetCurrentScene()->AddGameObject(object);

	object = new GameObject();
	_sampleUIImage = object;
	object->GetTransform()->SetPosition(Vector3(200, -150, -1));
	object->GetTransform()->SetScale(Vector3(2, 2, 2));
	UIText* ui_text = object->AddComponent<UIText>();
	ui_text->SetMaterial(static_cast<Material*>(ResourceManager::getInstance().GetResource(22)));
	ui_text->SetFont(static_cast<Font*>(ResourceManager::getInstance().GetResource(21)));
	ui_text->SetString("Hello World!");
	SceneManager::getInstance().GetCurrentScene()->AddGameObject(object);
}