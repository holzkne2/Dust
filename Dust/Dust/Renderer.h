#pragma once
#include "Component.h"
#include <d3d11.h>
#include "MathF.h"
#include "Mesh.h"
#include "Material.h"

using namespace MathF;

class Renderer :
	public Component
{
public:
	Renderer();
	virtual ~Renderer();

	virtual void Awake() {}
	virtual void Update() {}

	//TODO: Remove params
	virtual bool Render(ID3D11DeviceContext*, ID3D11Device*, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color) = 0;

	void SetSharedMesh(Mesh* mesh) { _mesh = mesh; }
	Mesh* GetSharedMesh() { return _mesh; }

	void SetMaterial(Material* material) { _material = material; }
	Material* GetSharedMaterial() { return _material; }

	virtual void serialize(std::ostream& stream) = 0;
	virtual void deserialize(std::istream& stream) = 0;

protected:
	Mesh* _mesh;
	Material* _material;
};

