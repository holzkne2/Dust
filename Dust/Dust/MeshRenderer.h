#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Shader.h"

//TODO: Render Function
class MeshRenderer :
	public Component
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Awake();

	Mesh* GetSharedMesh() { return &_mesh; }

	void SetShader(Shader*);
	Shader* GetShader() { return _shader; }

private:
	//TODO: Make Pointer
	Mesh _mesh;
	Shader* _shader;
};

