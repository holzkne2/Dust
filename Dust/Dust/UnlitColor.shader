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
	float3 color : COLOR;
};

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
	o.color = i.color;

	return o;
}

float4 frag(PixelInputType i) : SV_TARGET
{
	return float4(i.color, 1);
}