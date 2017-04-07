#include "Texture2D.h"
#include "Graphics.h"

Texture2D::Texture2D()
{
	_texture = 0;
}

Texture2D::~Texture2D()
{
}

void Texture2D::Load()
{
	HRESULT result;

	result = D3DX11CreateShaderResourceViewFromFile(
		Graphics::getInstance().GetDirect3D()->GetDevice(),
		_path.c_str(),
		NULL, NULL, &_texture, NULL);
	if (FAILED(result))
		return;

	_isLoaded = true;
}

void Texture2D::Unload()
{
	_texture = 0;

	_isLoaded = false;
}