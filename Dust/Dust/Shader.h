#pragma once
#include "Object.h"
#include <d3d11.h>
#include <D3DX11async.h>
#include "MathF.h"

using namespace MathF;

//TODO: Add Lights
class Light;

class Shader :
	public Object
{
public:
	Shader();
	virtual ~Shader();

	virtual bool Initialize(ID3D11Device*, HWND) = 0;
	virtual void ShutDown();
	virtual void Render(ID3D11DeviceContext*, int, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color) = 0;

	//TODO: ?? / Better Shader Handler
	virtual bool LoadTexture(ID3D11Device*) { return true; }

	bool IsInitizlized() { return _isInitialized; }

protected:
	struct MatrixBufferType
	{
		Matrix4x4 world;
		Matrix4x4 view;
		Matrix4x4 projection;
	};

	struct LightBuffer
	{
		Color lightColor;
		Vector3 direction;
		float atten;
		Color ambient;
	};

	ID3D11VertexShader* _vertexShader;
	ID3D11PixelShader* _pixelShader;
	ID3D11InputLayout* _layout;
	ID3D11Buffer* _matrixBuffer;

	bool _isInitialized;
};

