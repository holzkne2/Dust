#pragma once
#include <iostream>
#include <string>

class Object
{
public:
	Object();
	virtual ~Object();

	//TODO: Base call to here
	virtual void serialize(std::ostream& stream) {}
	//TODO: Base call to here
	virtual void deserialize(std::istream& stream) {}
};

