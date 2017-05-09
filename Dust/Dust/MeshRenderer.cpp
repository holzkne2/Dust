#include "MeshRenderer.h"
#include "System.h"

MeshRenderer::MeshRenderer()
{
	_material = 0;
}


MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::Awake()
{
	SceneManager::getInstance().GetCurrentScene()->AddMeshRenderer(this);
}