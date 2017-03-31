#include "Mesh.h"

#include <time.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

Mesh::Mesh()
{
	_vertexBuffer = 0;
	_indexBuffer = 0;

	_isInitialized = false;
}


Mesh::~Mesh()
{
}

void Mesh::TriangleTest()
{
	_vertices.clear();
	_colors.clear();
	_triangles.clear();
	_uvs.clear();

	//srand(time(NULL));
	Color color;
	color.r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.a = 1;

	_vertices.push_back(Vector3(-1.0, -1.0, 0.0));
	_colors.push_back(color);

	_vertices.push_back(Vector3(0.0, 1.0, 0.0));
	_colors.push_back(color);

	_vertices.push_back(Vector3(1.0, -1.0, 0.0));
	_colors.push_back(color);

	_triangles.push_back(0);
	_triangles.push_back(1);
	_triangles.push_back(2);

	RecalculateNormals();
}

void Mesh::CubeTest()
{
	_vertices.clear();
	_colors.clear();
	_triangles.clear();
	_uvs.clear();

	Color color = Color::Yellow;
	/*color.r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	color.a = 1;*/

	int facecount = 0;

	//Top
	_vertices.push_back(Vector3(-0.5, 0.5, -0.5));
	_vertices.push_back(Vector3(-0.5, 0.5, 0.5));
	_vertices.push_back(Vector3(0.5, 0.5, 0.5));
	_vertices.push_back(Vector3(0.5, 0.5, -0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	//North
	_vertices.push_back(Vector3(-0.5, 0.5, 0.5));
	_vertices.push_back(Vector3(-0.5, -0.5, 0.5));
	_vertices.push_back(Vector3(0.5, -0.5, 0.5));
	_vertices.push_back(Vector3(0.5, 0.5, 0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	//East
	_vertices.push_back(Vector3(0.5, 0.5, -0.5));
	_vertices.push_back(Vector3(0.5, 0.5, 0.5));
	_vertices.push_back(Vector3(0.5, -0.5, 0.5));
	_vertices.push_back(Vector3(0.5, -0.5, -0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	//South
	_vertices.push_back(Vector3(-0.5, 0.5, -0.5));
	_vertices.push_back(Vector3(0.5, 0.5, -0.5));
	_vertices.push_back(Vector3(0.5, -0.5, -0.5));
	_vertices.push_back(Vector3(-0.5, -0.5, -0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	//West
	_vertices.push_back(Vector3(-0.5, 0.5, -0.5));
	_vertices.push_back(Vector3(-0.5, -0.5, -0.5));
	_vertices.push_back(Vector3(-0.5, -0.5, 0.5));
	_vertices.push_back(Vector3(-0.5, 0.5, 0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	//Bottom
	_vertices.push_back(Vector3(-0.5, -0.5, -0.5));
	_vertices.push_back(Vector3(0.5, -0.5, -0.5));
	_vertices.push_back(Vector3(0.5, -0.5, 0.5));
	_vertices.push_back(Vector3(-0.5, -0.5, 0.5));

	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 1);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4);
	_triangles.push_back(facecount * 4 + 2);
	_triangles.push_back(facecount * 4 + 3);

	facecount++;

	for (int i = 0; i < _vertices.size(); i++)
		_colors.push_back(color);

	for (int i = 0; i < _vertices.size(); i += 4)
	{
		_uvs.push_back(Vector2(0, 0));
		_uvs.push_back(Vector2(1, 0));
		_uvs.push_back(Vector2(1, 1));
		_uvs.push_back(Vector2(0, 1));
	}

	RecalculateNormals();
}

void Mesh::RecalculateNormals()
{
	_normals.clear();
	std::vector<Vector3>* normal_buffer = new std::vector<Vector3>[_vertices.size()];

	for (int i = 0; i < _triangles.size(); i += 3)
	{
		Vector3 p1 = _vertices[_triangles[i + 1]] - _vertices[_triangles[i]];
		Vector3 p2 = _vertices[_triangles[i + 2]] - _vertices[_triangles[i]];
		Vector3 normal = Vector3::Cross(p1, p2);
		normal.Normalize();

		normal_buffer[_triangles[i]].push_back(normal);
		normal_buffer[_triangles[i + 1]].push_back(normal);
		normal_buffer[_triangles[i + 2]].push_back(normal);
	}

	for (int x = 0; x < _vertices.size(); ++x)
	{
		_normals.push_back(Vector3());
		for (int y = 0; y < normal_buffer[x].size(); ++y)
		{
			_normals[x] += normal_buffer[x][y];
		}
		_normals[x] /= normal_buffer[x].size();
	}

	normal_buffer->clear();
	delete [] normal_buffer;
}

bool Mesh::Initialize(ID3D11Device* device)
{
	bool result;

	// Initialize the vertex and index buffer that hold the geometry for the triangle.
	result = InitializeBuffers(device);
	if (!result)
		return false;

	return _isInitialized = true;
}

void Mesh::Shutdown()
{
	// Release the vertex and index buffers.
	ShutdownBuffers();

	return;
}

void Mesh::Render(ID3D11DeviceContext* deviceContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}

//TODO: Adapt to vertex size
bool Mesh::InitializeBuffers(ID3D11Device* device)
{
	VertexType* Full_vertices = new VertexType[_vertices.size()];
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	for (int i = 0; i < _vertices.size(); i++)
	{
		Full_vertices[i].position = _vertices[i];

		if (_colors.size() <= i)
			Full_vertices[i].color = Color();
		else
			Full_vertices[i].color = _colors[i];

		if (_uvs.size() <= i)
			Full_vertices[i].uv = Vector2();
		else
			Full_vertices[i].uv = _uvs[i];

		if (_normals.size() <= i)
			Full_vertices[i].normal = Vector3();
		else
			Full_vertices[i].normal = _normals[i];

		if (_tangents.size() <= i)
			Full_vertices[i].tangent = Vector3();
		else
			Full_vertices[i].tangent = _tangents[i];
	}

	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * _vertices.size();
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = Full_vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &_vertexBuffer);
	if (FAILED(result))
		return false;

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * _triangles.size();
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = &_triangles[0];
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &_indexBuffer);
	if (FAILED(result))
		return false;

	delete [] Full_vertices;

	return true;
}

void Mesh::ShutdownBuffers()
{
	// Release the index buffer.
	if (_indexBuffer)
	{
		_indexBuffer->Release();
		_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (_vertexBuffer)
	{
		_vertexBuffer->Release();
		_vertexBuffer = 0;
	}

	return;
}

void Mesh::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}