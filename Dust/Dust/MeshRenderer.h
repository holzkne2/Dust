#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Material.h"
#include "ResourceManager.h"
#include "Renderer.h"

//TODO: derive from renderer
//TODO: Render Function
class MeshRenderer :
	public Renderer
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Awake();

	virtual bool Render(ID3D11DeviceContext*, ID3D11Device*, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color);

	//TODO:Fix
	virtual void serialize(std::ostream& stream) {
		stream << "MeshRenderer ";
		stream << "Mesh " << _mesh->GetResourceID() << " Material " << _material->GetResourceID() << " ";
	}
	virtual void deserialize(std::istream& stream) {
		string word;
		unsigned long id;
		stream >> word;
		if (word == "Mesh")
		{
			stream >> id;
			_mesh = static_cast<Mesh*>(ResourceManager::getInstance().GetResource(id));
		}
		stream >> word;
		if (word == "Material")
		{
			stream >> id;
			_material = static_cast<Material*>(ResourceManager::getInstance().GetResource(id));
		}
	}
};

