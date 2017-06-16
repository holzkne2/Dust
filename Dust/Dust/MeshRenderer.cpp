#include "MeshRenderer.h"
#include "System.h"

MeshRenderer::MeshRenderer()
{
}


MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::Awake()
{
	SceneManager::getInstance().GetCurrentScene()->AddMeshRenderer(this);
}

bool MeshRenderer::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device, Matrix4x4 worldMatrix, Matrix4x4 viewMatrix, Matrix4x4 projectionMatrix, Light* lightPointer, Color ambient)
{
	if (!_mesh->IsInitizlized())
		if (!_mesh->InitializeStatic(device))
		{
			Debug::Error("Mesh Initialize Failed");
			return false;
		}
	_mesh->Render(deviceContext);

	_material->Render(deviceContext, _mesh->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		lightPointer, ambient);
	return true;
}