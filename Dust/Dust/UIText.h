#pragma once
#include "Renderer.h"
#include "Font.h"

class UIText :
	public Renderer
{
public:
	UIText();
	virtual ~UIText();

	virtual void Awake();

	virtual bool Render(ID3D11DeviceContext*, ID3D11Device*, Matrix4x4, Matrix4x4, Matrix4x4, Light*, Color);

	void SetString(string text) { _text = text; _dirty = true; }

	void SetFont(Font* font) { _font = font; _dirty = true; }

	virtual void serialize(std::ostream& stream) {}
	virtual void deserialize(std::istream& stream) {}

private:
	string _text;
	Font* _font;
	bool _dirty;
};

