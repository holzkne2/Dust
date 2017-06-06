#include "Debug.h"
#include <iostream>
#include <windows.h>

Debug::Debug()
{
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