#pragma once
#include <string>

class Debug
{
public:
	Debug();
	virtual ~Debug();

	static Debug& getInstance()
	{
		static Debug instance;
		return instance;
	}

	static void Message(std::string msg);
	static void Warning(std::string msg);
	static void Error(std::string msg);
};

