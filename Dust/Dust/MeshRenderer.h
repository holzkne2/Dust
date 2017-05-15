#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Material.h"
#include "ResourceManager.h"

//TODO: Render Function
class MeshRenderer :
	public Component
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Awake();

	void SetSharedMesh(Mesh* mesh) { _mesh = mesh; }
	Mesh* GetSharedMesh() { return _mesh; }

	void SetMaterial(Material* material) { _material = material; }
	Material* GetSharedMaterial() { return _material; }

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

private:
	Mesh* _mesh;
	Material* _material;
};

