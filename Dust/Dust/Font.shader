cbuffer MatrixBufferType
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

struct VertexInputType
{
	float4 position : POSITION;
	float2 uv : TEXCOORD0;
	float3 normal : NORMAL;
	float3 tangent : TANGENT;
	float3 color : COLOR;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD0;
};

//TODO: Add color
Texture2D _MainTex;
SamplerState SampleType;

PixelInputType vert(VertexInputType i)
{
	PixelInputType o;

	// Change the position vector to be 4 units for proper matrix calculations.
	i.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.
	o.position = mul(i.position, worldMatrix);
	o.position = mul(o.position, viewMatrix);
	o.position = mul(o.position, projectionMatrix);

	// Store the input color for the pixel shader to use.
	o.uv = i.uv;

	return o;
}

float4 frag(PixelInputType i) : SV_TARGET
{
	float4 color;

	color = _MainTex.Sample(SampleType, i.uv);
	//TODO: Real Alpha
	if (color.r <= 0.3)
		color.a = 0.0;
	else
		color.a = 1.0;

	return color;
}