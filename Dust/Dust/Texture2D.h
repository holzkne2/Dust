#pragma once
#include "Resource.h"
#include <d3d11.h>
#include <d3dx11tex.h>

class Texture2D :
	public Resource
{
public:
	Texture2D();
	virtual ~Texture2D();

	virtual void Load();
	virtual void Unload();

	ID3D11ShaderResourceView* GetTexure() { return _texture; }

private:
	ID3D11ShaderResourceView* _texture;
};

