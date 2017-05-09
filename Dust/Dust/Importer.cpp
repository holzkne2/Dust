#include "Importer.h"
#include "MathF.h"
#include <vector>
#include "FileHelperDust.h"

using namespace MathF;
using namespace std;

//Coverts Right Hand to Left Hand
void ObjToMesh(std::wstring path, Mesh* const &mesh)
{
	typedef struct
	{
		int v1, v2, v3;
		int vt1, vt2, vt3;
		int vn1, vn2, vn3;
	} Face;

	vector<string> vtokens;
	Face currFace;

	vector<Vector3> v;
	vector<Vector2> vt;
	vector<Vector3> vn;
	vector<Face> f;

	vector<Vector3> full_v;
	vector<Vector2> full_vt;
	vector<Vector3> full_vn;
	vector<int> full_f;

	vector<string> tokens = GetTokensFromFile(wstos(path));

	mesh->Clear();

	int t = 0;
	while (t < tokens.size())
	{
		if (tokens[t] == "v")
		{
			v.push_back(Vector3(stof(tokens[1+t]), stof(tokens[2+t]), 0 - stof(tokens[3+t])));
			t += 4;
		}
		else if (tokens[t] == "vt")
		{
			vt.push_back(Vector2(stof(tokens[1+t]), 1 - stof(tokens[2+t])));
			t += 3;
		}
		else if (tokens[t] == "vn")
		{
			vn.push_back(Vector3(stof(tokens[1+t]), stof(tokens[2+t]), 0 - stof(tokens[3+t])));
			t += 4;
		}
		else if (tokens[t] == "f")
		{
			vtokens = GetTokens(tokens[++t], '/');
			currFace.v3 = stoi(vtokens[0]);
			currFace.vt3 = stoi(vtokens[1]);
			currFace.vn3 = stoi(vtokens[2]);

			vtokens = GetTokens(tokens[++t], '/');
			currFace.v2 = stoi(vtokens[0]);
			currFace.vt2 = stoi(vtokens[1]);
			currFace.vn2 = stoi(vtokens[2]);

			vtokens = GetTokens(tokens[++t], '/');
			currFace.v1 = stoi(vtokens[0]);
			currFace.vt1 = stoi(vtokens[1]);
			currFace.vn1 = stoi(vtokens[2]);

			f.push_back(currFace);
		}
		else
		{
			++t;
		}
	}

	//TODO: Vertex Compression
	//TODO: Direct Write to Mesh (Could make compression harder)
	for (int i = 0; i < f.size(); ++i)
	{
		currFace = f[i];

		full_v.push_back(v[currFace.v1 - 1]);
		full_vt.push_back(vt[currFace.vt1 - 1]);
		full_vn.push_back(vn[currFace.vn1 - 1]);

		full_v.push_back(v[currFace.v2 - 1]);
		full_vt.push_back(vt[currFace.vt2 - 1]);
		full_vn.push_back(vn[currFace.vn2 - 1]);

		full_v.push_back(v[currFace.v3 - 1]);
		full_vt.push_back(vt[currFace.vt3 - 1]);
		full_vn.push_back(vn[currFace.vn3 - 1]);

		full_f.push_back((i * 3));
		full_f.push_back((i * 3) + 1);
		full_f.push_back((i * 3) + 2);
	}

	mesh->SetVertices(full_v);
	mesh->SetUVs(full_vt);
	mesh->SetNormals(full_vn);
	mesh->SetTriangles(full_f);
}
