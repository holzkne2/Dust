#pragma once
#include "Shader.h"

using namespace MathF;

class UnlitColorShader :
	public Shader
{
public:
	UnlitColorShader();
	virtual ~UnlitColorShader();

	virtual bool Initialize(ID3D11Device*, HWND);
	virtual void ShutDown();
	virtual void Render(ID3D11DeviceContext*, int, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*);
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, Matrix4x4, Matrix4x4, Matrix4x4);
	void RenderShader(ID3D11DeviceContext*, int);
};

