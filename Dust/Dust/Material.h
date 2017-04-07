#pragma once
#include "Resource.h"
#include <d3d11.h>
#include <D3DX11async.h>
#include "MathF.h"
#include "Light.h"
#include "FileHelperDust.h"
#include <map>
#include "Texture2D.h"

using namespace MathF;
using namespace std;

class Material :
	public Resource
{
public:
	Material();
	virtual ~Material();

	virtual void Load();
	virtual void Unload();

	void Render(ID3D11DeviceContext*, int, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color);

private:
	bool ReadMatFile();
	bool InitializeShader(ID3D11Device*, HWND);

	void OutputShaderErrorMessage(ID3D10Blob*, HWND);

	bool SetShaderParameters(ID3D11DeviceContext*, Matrix4x4, Matrix4x4, Matrix4x4);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	struct MatrixBufferType
	{
		Matrix4x4 world;
		Matrix4x4 view;
		Matrix4x4 projection;
	};

	struct  LightBuffer
	{
		Color lightColor;
		Vector3 direction;
		float atten;
		Color ambient;
	};

private:
	ID3D11VertexShader* _vertexShader;
	ID3D11PixelShader* _pixelShader;
	ID3D11InputLayout* _layout;
	ID3D11Buffer* _matrixBuffer;

	wstring _shaderfilename;

	map<string, Texture2D*> _textures;
	ID3D11SamplerState* _sampleState;
};