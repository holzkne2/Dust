#include "Font.h"
#include "Font.h"


Font::Font()
{
}


Font::~Font()
{
}

void Font::Load()
{
	_isLoaded = Initialize();
}

void Font::Unload()
{
	ReleaseFontData();
	_isLoaded = false;
}

bool Font::Initialize()
{
	return LoadFontData();
}

bool Font::LoadFontData()
{
	vector<string> tokens = GetTokensFromFile(wstos(_path), '\t');
	FontType temp;

	for (int i = 0; i < tokens.size(); i += 5)
	{
		temp.left = stof(tokens[i+2]);
		temp.right = stof(tokens[i+3]);
		temp.size = stoi(tokens[i+4]);
		_font.push_back(temp);
	}

	return true;
}

void Font::ReleaseFontData()
{
	// Release the font data array.
	_font.clear();
}

void Font::BuildVertexArray(Mesh* output, string text)
{
	std::vector<Vector3> vertices;
	std::vector<Vector2> uvs;
	std::vector<int> triangles;

	int letter = 0;
	int quad = 0;
	int x = 0;

	output->Clear();

	for (int i = 0; i < text.size(); ++i)
	{
		letter = ((int)text[i]) - 32;

		// If the letter is a space then just move over three pixels.
		if (letter == 0)
			x += 3;
		else
		{
			vertices.push_back(Vector3(x, 0, 0)); //Top Left
			uvs.push_back(Vector2(_font[letter].left, 0.0));
			triangles.push_back(quad * 5);

			vertices.push_back(Vector3(x + _font[letter].size, -16, 0)); //Bottom Right
			uvs.push_back(Vector2(_font[letter].right, 0.9));
			triangles.push_back(quad * 5 + 1);

			vertices.push_back(Vector3(x, -16, 0)); //Bottom Left
			uvs.push_back(Vector2(_font[letter].left, 0.9));
			triangles.push_back(quad * 5 + 2);

			triangles.push_back(quad * 5);

			vertices.push_back(Vector3(x + _font[letter].size, 0, 0)); //Top Right
			uvs.push_back(Vector2(_font[letter].right, 0.0));
			triangles.push_back(quad * 5 + 3);

			vertices.push_back(Vector3(x + _font[letter].size, -16, 0)); //Bottom Right
			uvs.push_back(Vector2(_font[letter].right, 0.9));
			triangles.push_back(quad * 5 + 4);

			quad++;
			// Update the x location for drawing by the size of the letter and one pixel.
			x += _font[letter].size + 1;
		}
	}

	output->SetVertices(vertices);
	output->SetUVs(uvs);
	output->SetTriangles(triangles);
}