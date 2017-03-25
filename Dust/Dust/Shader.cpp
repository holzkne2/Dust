#include "Shader.h"


Shader::Shader()
{
	_vertexShader = 0;
	_pixelShader = 0;
	_layout = 0;
	_matrixBuffer = 0;

	_isInitialized = false;
}


Shader::~Shader()
{
}

void Shader::ShutDown()
{
	if (_matrixBuffer)
	{
		_matrixBuffer->Release();
		_matrixBuffer = 0;
	}

	// Release the layout.
	if (_layout)
	{
		_layout->Release();
		_layout = 0;
	}

	// Release the pixel shader.
	if (_pixelShader)
	{
		_pixelShader->Release();
		_pixelShader = 0;
	}

	// Release the vertex shader.
	if (_vertexShader)
	{
		_vertexShader->Release();
		_vertexShader = 0;
	}
}