#include "UIImage.h"
#include "ResourceManager.h"

UIImage::UIImage()
{
	_texture = 0;
	_dirty = true;
}


UIImage::~UIImage()
{
	if (_mesh)
		delete _mesh;
}

void UIImage::Awake()
{
}

//Create mesh vertices in correct size of image
void UIImage::CreateMesh()
{
	std::vector<Vector3> vertices;
	std::vector<Vector2> uvs;
	std::vector<int> triangles;
	float left = 0, bottom = 0;
	float right = 128, top = 128;
	//float left = -540.000000, bottom = 19.0000000;
	//float right = -284.000000, top = 275.000000;

	_mesh->Clear();

	vertices.push_back(Vector3(left, top, 0));
	uvs.push_back(Vector2(0, 0));

	vertices.push_back(Vector3(right, bottom, 0));
	uvs.push_back(Vector2(1, 1));

	vertices.push_back(Vector3(left, bottom, 0));
	uvs.push_back(Vector2(0, 1));

	triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(2);

	vertices.push_back(Vector3(left, top, 0));
	uvs.push_back(Vector2(0, 0));

	vertices.push_back(Vector3(right, top, 0));
	uvs.push_back(Vector2(1, 0));

	vertices.push_back(Vector3(right, bottom, 0));
	uvs.push_back(Vector2(1, 1));

	triangles.push_back(3);
	triangles.push_back(4);
	triangles.push_back(5);

	_mesh->SetVertices(vertices);
	_mesh->SetUVs(uvs);
	_mesh->SetTriangles(triangles);
}

bool UIImage::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device, Matrix4x4 worldMatrix, Matrix4x4 viewMatrix, Matrix4x4 projectionMatrix, Light* lightPointer, Color ambient)
{
	//TODO: Hand Texture to Material
	if (!_mesh || !_mesh->IsInitizlized())
	{
		//TODO: Should this be creating it's own mesh
		_mesh = new Mesh();
		CreateMesh();
		if(!_mesh->InitializeDynamic(device))
		{
			Debug::Error("Mesh Initialize Failed");
			return false;
		}
		_dirty = false;
	}
	else if (_dirty)
	{
		CreateMesh();
		if (!_mesh->UpdateDynamicBuffers(deviceContext))
		{
			Debug::Error("Mesh Initialize Failed");
			return false;
		}
		_dirty = false;
	}

	_mesh->Render(deviceContext);

	if (!_material)
		_material = static_cast<Material*>(ResourceManager::getInstance().GetResource(19));
	_material->Render(deviceContext, _mesh->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		lightPointer, ambient);
	return true;
}