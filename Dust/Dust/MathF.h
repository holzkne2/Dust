#pragma once

#include <math.h>
#include <algorithm>

#define PI 3.14159265

namespace MathF
{
	struct Vector2
	{
		//variables
		float x, y;

		//constructors
		Vector2() { x = 0; y = 0; }
		Vector2(float _x, float _y) { x = _x; y = _y; }

		//public functions
		float Magnitude() const;
		float SqrMagnitude() const;

		Vector2 Normalized() const;
		void Normalize();

		//static functions
		static float Angle(const Vector2& a, const Vector2& b);
		static float Distance(const Vector2& a, const Vector2& b);
		static float Dot(const Vector2& lhs, const Vector2& rhs);
		static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
		static Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t);
		static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);
		 
		//comparison operators
		bool operator == (const Vector2& v) const;
		bool operator != (const Vector2& v) const;

		//unary operators
		Vector2 operator- () const { return Vector2(-x, -y); }

		//assignment operators
		Vector2& operator= (const Vector2& v);
		Vector2& operator+= (const Vector2& v);
		Vector2& operator-= (const Vector2& v);
		Vector2& operator*= (float s);
		Vector2& operator/= (float s);

		//static variables
		static const Vector2 Down;
		static const Vector2 Left;
		static const Vector2 One;
		static const Vector2 Right;
		static const Vector2 Up;
		static const Vector2 Zero;
	};

	// Binary operators
	Vector2 operator+ (const Vector2& a, const Vector2& b);
	Vector2 operator- (const Vector2& a, const Vector2& b);
	Vector2 operator* (const Vector2& v, float s);
	Vector2 operator/ (const Vector2& a, float s);
	Vector2 operator* (float s, const Vector2& v);

	struct Vector3
	{
		//variables
		float x, y, z;

		//constructors
		Vector3() { x = 0; y = 0; z = 0; }
		Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

		//public functions
		float Magnitude() const;
		float SqrMagnitude() const;

		Vector3 Normalized() const;
		void Normalize();

		//static functions
		static float Angle(const Vector3& a, const Vector3& b);
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
		static float Distance(const Vector3& a, const Vector3& b);
		static float Dot(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Lerp(const Vector3& a, const Vector3& b, float t);
		static Vector3 LerpUnclamped(const Vector3& a, const Vector3& b, float t);
		static Vector3 Reflect(const Vector3& inDirection, const Vector3& inNormal);

		//comparison operators
		bool operator == (const Vector3& v) const;
		bool operator != (const Vector3& v) const;

		//unary operators
		Vector3 operator- () const { return Vector3(-x, -y, -z); }

		//assignment operators
		Vector3& operator= (const Vector3& v);
		Vector3& operator+= (const Vector3& v);
		Vector3& operator-= (const Vector3& v);
		Vector3& operator*= (float s);
		Vector3& operator/= (float s);

		//static variables
		static const Vector3 Back;
		static const Vector3 Down;
		static const Vector3 Forward;
		static const Vector3 Left;
		static const Vector3 One;
		static const Vector3 Right;
		static const Vector3 Up;
		static const Vector3 Zero;
	};

	// Binary operators
	Vector3 operator+ (const Vector3& a, const Vector3& b);
	Vector3 operator- (const Vector3& a, const Vector3& b);
	Vector3 operator* (const Vector3& v, float s);
	Vector3 operator/ (const Vector3& a, float s);
	Vector3 operator* (float s, const Vector3& v);

	struct Quaternion
	{
		//variables
		float x, y, z, w;

		//constructors
		Quaternion() { x = 0; y = 0; z = 0; w = 1.0; }
		Quaternion(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }

		//public functions
		Vector3 EulerAngles() const;
		Quaternion Normalized() const;
		void Normalize();

		//static functions
		static Quaternion Conjugate(const Quaternion& rotation);
		static Quaternion Euler(const Vector3& euler);
		static Quaternion Inverse(const Quaternion& rotation);

		//comparison operators
		bool operator == (const Quaternion& q) const;
		bool operator != (const Quaternion& q) const;

		//unary operators
		Quaternion operator- () const { return Quaternion(-x, -y, -z, -w); };

		//assignment operators
		Quaternion& operator= (const Quaternion& q);
		Quaternion& operator+= (const Quaternion& q);
		Quaternion& operator-= (const Quaternion& q);
		Quaternion& operator*= (const Quaternion& q);
		Quaternion& operator*= (float s);
		Quaternion& operator/= (const Quaternion& q);

		//constants
		static const Quaternion Identity;
	};

	//binary operators
	Quaternion operator+ (const Quaternion& a, const Quaternion& b);
	Quaternion operator- (const Quaternion& a, const Quaternion& b);
	Quaternion operator* (const Quaternion& a, const Quaternion& b);
	Quaternion operator* (const Quaternion& q, float s);
	Quaternion operator/ (const Quaternion& a, const Quaternion& b);
	Quaternion operator* (float s, const Quaternion& q);

	struct Matrix4x4
	{
		//variables
		union {
			struct {
				float        _11, _12, _13, _14;
				float        _21, _22, _23, _24;
				float        _31, _32, _33, _34;
				float        _41, _42, _43, _44;

			};
			float _m[4][4];
			float _ms[16];
		};

		//constructors
		Matrix4x4() { *this = Matrix4x4::Identity; };
		Matrix4x4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			_11 = m00; _12 = m01; _13 = m02; _14 = m03;
			_21 = m10; _22 = m11; _23 = m12; _24 = m13;
			_31 = m20; _32 = m21; _33 = m22; _34 = m23;
			_41 = m30; _42 = m31; _43 = m32; _44 = m33;
		}

		//public functions
		float Determinant() const;

		//static functions
		static Matrix4x4 Frustum(float xmin, float xmax, float ymin, float ymax, float zNear, float zFar);
		static Matrix4x4 Inverse(const Matrix4x4& m);
		static Matrix4x4 Perspective(float fov, float aspect, float zNear, float zFar);
		static Matrix4x4 Rotation(const Quaternion& q);
		static Matrix4x4 Scale(const Vector3& s);
		static Matrix4x4 Scale(float s);
		static Matrix4x4 Translate(const Vector3& pos);
		static Matrix4x4 Transpose(const Matrix4x4& m);
		static Matrix4x4 TRS(const Vector3& pos, const Quaternion& q, const Vector3& s);

		//comparison operators
		bool operator == (const Matrix4x4& m) const;
		bool operator != (const Matrix4x4& m) const;

		//assignment operators
		Matrix4x4& operator= (const Matrix4x4& m);
		Matrix4x4& operator*= (const Matrix4x4& m);
		Matrix4x4& operator*= (float s);

		//constants
		static const Matrix4x4 Identity;
		static const Matrix4x4 Zero;
	};

	Matrix4x4 operator* (const Matrix4x4& a, const Matrix4x4& b);
	Matrix4x4 operator* (const Matrix4x4& m, float s);

	struct Color
	{
		//variables
		float r, g, b, a;

		//constructors
		Color() { r = 0; g = 0; b = 0; a = 1.0; }
		Color(float _r, float _g, float _b) { r = _r; g = _g; b = _b; a = 1.0; }
		Color(float _r, float _g, float _b, float _a) { r = _r; g = _g; b = _b; a = _a; }

		//public functions

		//static functions
		static Color Lerp(const Color& a, const Color& b, float t);
		static Color LerpUnclamped(const Color& a, const Color& b, float t);

		//comparison operators
		bool operator == (const Color& c) const;
		bool operator != (const Color& c) const;

		// Unary operators
		Color operator- () const;

		// Assignment operators
		Color& operator= (const Color& c);
		Color& operator+= (const Color& c);
		Color& operator-= (const Color& c);
		Color& operator*= (const Color& c);
		Color& operator*= (float s);
		Color& operator/= (const Color& c);

		//constants
		static const Color Black;
		static const Color Blue;
		static const Color Clear;
		static const Color Cyan;
		static const Color Gray;
		static const Color Green;
		static const Color Grey;
		static const Color Magenta;
		static const Color Red;
		static const Color White;
		static const Color Yellow;
	};

	// Binary operators
	Color operator+ (const Color& a, const Color& b);
	Color operator- (const Color& a, const Color& b);
	Color operator* (const Color& a, const Color& b);
	Color operator* (const Color& c, float s);
	Color operator/ (const Color& a, const Color& b);
	Color operator* (float s, const Color& c);

#include "MathF.inl"
};