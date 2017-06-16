#pragma once
#include "Component.h"
#include <d3d11.h>
#include <vector>
#include "MathF.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "Light.h"

using namespace MathF;

class UIImage :
	public Renderer
{
public:
	UIImage();
	virtual ~UIImage();

	virtual void Awake();

	virtual bool Render(ID3D11DeviceContext*, ID3D11Device*, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color);
	
	int GetIndexCount();

	void SetTexture(Texture2D* const texture) { _texture = texture; _dirty = true; }

	virtual void serialize(std::ostream& stream) {}
	virtual void deserialize(std::istream& stream) {}

private:
	void CreateMesh();

private:
	Texture2D* _texture;
	bool _dirty;
};

