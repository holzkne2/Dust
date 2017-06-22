#include "UIText.h"


UIText::UIText()
{
	_text = "";
	_font = 0;
	_dirty = true;
}


UIText::~UIText()
{
}

void UIText::Awake()
{
}

bool UIText::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device, Matrix4x4 worldMatrix, Matrix4x4 viewMatrix, Matrix4x4 projectionMatrix, Light* lightPointer, Color ambient)
{
	if (!_mesh || !_mesh->IsInitizlized())
	{
		_mesh = new Mesh();
		_font->BuildVertexArray(_mesh, _text);
		if (!_mesh->InitializeDynamic(device))
		{
			Debug::Error("Mesh Initialize Failed");
			return false;
		}
		_dirty = false;
	}
	else if (_dirty)
	{
		_font->BuildVertexArray(_mesh, _text);
		if (!_mesh->UpdateDynamicBuffers(deviceContext))
		{
			Debug::Error("Mesh Initialize Failed");
			return false;
		}
		_dirty = false;
	}

	_mesh->Render(deviceContext);

	_material->Render(deviceContext, _mesh->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		lightPointer, ambient);
	return true;
}