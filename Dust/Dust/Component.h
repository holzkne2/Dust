#pragma once
#include "Object.h"
class Component :
	public Object
{
public:
	Component();
	virtual ~Component();

	virtual void Awake() {};
	virtual void Start() {};
	virtual void Update() {};

	
};

