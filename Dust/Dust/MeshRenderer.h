#pragma once
#include "Component.h"
#include "Mesh.h"

class MeshRenderer :
	public Component
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Start();

private:
	Mesh _mesh;
};

