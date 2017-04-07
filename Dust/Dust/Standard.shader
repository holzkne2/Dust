cbuffer MatrixBufferType
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

cbuffer LightBuffer
{
	float4 ambientColor;
	float4 lightColor;
	float3 lightDirection;
	float atten;
}

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
	float3 normal : NORMAL;
};

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

	o.normal = mul(i.normal, (float3x3)worldMatrix);
	o.normal = normalize(o.normal);

	return o;
}

float4 frag(PixelInputType i) : SV_TARGET
{
	float4 tex = _MainTex.Sample(SampleType, i.uv);
	float light = saturate(dot(i.normal, -lightDirection));
	float3 col = saturate((light * lightColor * tex * atten) + (ambientColor * tex));
	return float4(col, 1);
}