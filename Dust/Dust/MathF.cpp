#include "MathF.h"

namespace MathF
{
	const Vector2 Vector2::Down = Vector2(0.0, -1.0);
	const Vector2 Vector2::Left = Vector2(-1.0, 0.0);
	const Vector2 Vector2::One = Vector2(1.0, 1.0);
	const Vector2 Vector2::Right = Vector2(1.0, 0.0);
	const Vector2 Vector2::Up = Vector2(0.0, 1.0);
	const Vector2 Vector2::Zero = Vector2(0.0, 0.0);

	const Vector3 Vector3::Back = Vector3(0.0, 0.0, -1.0);
	const Vector3 Vector3::Down = Vector3(0.0, -1.0, 0.0);
	const Vector3 Vector3::Forward = Vector3(0.0, 0.0, 1.0);
	const Vector3 Vector3::Left = Vector3(-1.0, 0.0, 0.0);
	const Vector3 Vector3::One = Vector3(1.0, 1.0, 1.0);
	const Vector3 Vector3::Right = Vector3(1.0, 0.0, 0.0);
	const Vector3 Vector3::Up = Vector3(0.0, 1.0, 0.0);
	const Vector3 Vector3::Zero = Vector3(0.0, 0.0, 0.0);

	const Quaternion Quaternion::Identity = Quaternion(0.0, 0.0, 0.0, 1.0);

	const Matrix4x4 Matrix4x4::Identity = Matrix4x4(1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
	const Matrix4x4 Matrix4x4::Zero = Matrix4x4(0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0);

	const Color Color::Black = Color(0.0, 0.0, 0.0, 1.0);
	const Color Color::Blue = Color(0.0, 0.0, 1.0, 1.0);
	const Color Color::Clear = Color(0.0, 0.0, 0.0, 0.0);
	const Color Color::Cyan = Color(0.0, 1.0, 1.0, 1.0);
	const Color Color::Gray = Color(0.5, 0.5, 0.5, 1.0);
	const Color Color::Green = Color(0.0, 1.0, 0.0, 1.0);
	const Color Color::Magenta = Color(1.0, 0.0, 1.0, 1.0);
	const Color Color::Red = Color(1.0, 0.0, 0.0, 1.0);
	const Color Color::White = Color(1.0, 1.0, 1.0, 1.0);
	const Color Color::Yellow = Color(1.0, 0.92, 0.016, 1.0);
}