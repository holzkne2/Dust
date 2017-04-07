#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Material.h"

//TODO: Render Function
class MeshRenderer :
	public Component
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Awake();

	Mesh* GetSharedMesh() { return &_mesh; }

	void SetMaterial(Material* material) { _material = material; }
	Material* GetSharedMaterial() { return _material; }

private:
	//TODO: Make Pointer
	Mesh _mesh;
	Material* _material;
};

