#pragma once
#include "Object.h"
#include <d3d11.h>
#include "MathF.h"
#include <vector>

using namespace MathF;

class Mesh :
	public Object
{
public:
	Mesh();
	virtual ~Mesh();

	void SetVertices(const std::vector<Vector3>& vertices) { _vertices = vertices; }
	const std::vector<Vector3>& GetVertices() { return _vertices; }

	int GetIndexCount() { return _triangles.size(); }

	bool Initialize(ID3D11Device*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	void RecalculateNormals();
	
	void TriangleTest();
	void CubeTest();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

private:
	struct  appdata_base
	{
		Vector3 position;
		Vector2 uv;
		Vector3 normal;
	};

	struct  appdata_tan
	{
		Vector3 position;
		Vector2 uv;
		Vector3 normal;
		Vector3 tangent;
	};

	struct  appdata_full
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
};

