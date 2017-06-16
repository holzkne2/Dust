#pragma once
#include "Object.h"
#include <d3d11.h>
#include "MathF.h"
#include "Resource.h"
#include <vector>

using namespace MathF;

class Mesh :
	public Resource
{
public:
	Mesh();
	virtual ~Mesh();

	virtual void Load();
	virtual void Unload();

	//TODO: Make Less Mem Intensive
	void SetVertices(const std::vector<Vector3>& vertices) { _vertices = vertices; }
	std::vector<Vector3>* GetVertices() { return &_vertices; }

	void SetColors(const std::vector<Color>& colors) { _colors = colors; }
	std::vector<Color>* GetColors() { return &_colors; }
	
	void SetTriangles(const std::vector<int>& triangles) { _triangles = triangles; }
	std::vector<int>* GetTriangles() { return &_triangles; }
	
	void SetUVs(const std::vector<Vector2>& uvs) { _uvs = uvs; }
	std::vector<Vector2>* GetUVs() { return &_uvs; }
	
	void SetNormals(const std::vector<Vector3>& normals) { _normals = normals; }
	std::vector<Vector3>* GetNormals() { return &_normals; }

	void SetTangents(const std::vector<Vector3>& tangents) { _tangents = tangents; }
	std::vector<Vector3>* GetTangents() { return &_tangents; }

	int GetIndexCount() { return _triangles.size(); }

	//TODO: remove
	//bool Initialize(ID3D11Device*);

	bool InitializeStatic(ID3D11Device*);
	bool InitializeDynamic(ID3D11Device*);
	void Render(ID3D11DeviceContext*);
	bool UpdateDynamicBuffers(ID3D11DeviceContext*);

	void RecalculateNormals();
	
	void Clear();

	bool IsInitizlized() { return _isInitialized; }

private:
	void Shutdown();

	//bool InitializeBuffers(ID3D11Device*);
	bool InitializeStaticBuffers(ID3D11Device*);
	bool InitializeDynamicBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	//TODO: Remove/Relocate
	void TriangleTest();
	void CubeTest();
private:
	//struct  appdata_base
	//{
	//	Vector3 position;
	//	Vector2 uv;
	//	Vector3 normal;
	//};

	//struct  appdata_tan
	//{
	//	Vector3 position;
	//	Vector2 uv;
	//	Vector3 normal;
	//	Vector3 tangent;
	//};

	struct  VertexType
	{
		Vector3 position;
		Vector2 uv;
		Vector3 normal;
		Vector3 tangent;
		Color color;
	};

private:
	std::vector<Vector3> _vertices;
	std::vector<Color> _colors;
	std::vector<int> _triangles;
	std::vector<Vector2> _uvs;
	std::vector<Vector3> _normals;
	std::vector<Vector3> _tangents;

	ID3D11Buffer *_vertexBuffer, *_indexBuffer;

	//TODO: competes with _isLoaded
	bool _isInitialized;
};

