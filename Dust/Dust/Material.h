#pragma once
#include "Resource.h"
#include <d3d11.h>
#include <D3DX11async.h>
#include "MathF.h"

using namespace MathF;

class Material :
	public Resource
{
public:
	Material();
	virtual ~Material();

	virtual void Load();
	virtual void Unload();
};

