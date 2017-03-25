#include "MeshRenderer.h"
#include "System.h"

MeshRenderer::MeshRenderer()
{

	_shader = 0;
	
	Awake();
}


MeshRenderer::~MeshRenderer()
{
	//if (_shader)
	//	delete _shader;
}

void MeshRenderer::Awake()
{
	System::getInstance().GetScene()->AddMeshRenderer(this);
}

void MeshRenderer::SetShader(Shader* shader)
{
	//TODO:Check Init / Better Shader Handlers
	_shader = shader;
}