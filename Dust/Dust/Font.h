#pragma once
#include "Resource.h"
#include <d3d11.h>
#include "Texture2D.h"
#include "Mesh.h"

class Font :
	public Resource
{
public:
	Font();
	virtual ~Font();

	virtual void Load();
	virtual void Unload();

	bool Initialize();

	void BuildVertexArray(Mesh*, string);

private:
	bool LoadFontData();
	void ReleaseFontData();

private:
	struct FontType
	{
		float left, right;
		int size;
	};

private:
	vector<FontType> _font;
};

