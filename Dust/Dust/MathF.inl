#pragma once

using namespace MathF;
using namespace std;

// Vector2

inline float Vector2::Magnitude() const
{
	return sqrt((x * x) + (y * y));
}

inline float Vector2::SqrMagnitude() const
{
	return (x * x) + (y * y);
}

inline Vector2 Vector2::Normalized() const
{
	return (*this) / Magnitude();
}

inline void Vector2::Normalize()
{
	(*this) = Normalized();
}

inline float Vector2::Angle(const Vector2& a, const Vector2& b)
{
	return acos(Vector2::Dot(a, b) / (a.Magnitude() * b.Magnitude())) * 180.0 / PI;
}

inline float Vector2::Distance(const Vector2& a, const Vector2& b)
{
	return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

inline float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
{
	return lhs.Magnitude() * rhs.Magnitude() * cos(Vector2::Angle(lhs, rhs) * PI / 180.0);
}

inline Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t)
{
	t = std::min<float>(1.0, std::max<float>(0.0, t));
	return (1.0 - t) * a + t * b;
}

inline Vector2 Vector2::LerpUnclamped(const Vector2& a, const Vector2& b, float t)
{
	return (1.0 - t) * a + t * b;
}

inline Vector2 Vector2::Reflect(const Vector2& inDirection, const Vector2& inNormal)
{
	return -2.0 * Vector2::Dot(inDirection, inNormal) * inNormal + inDirection;
}

inline bool Vector2::operator == (const Vector2& v) const
{
	return x == v.x && y == v.y;
}

inline bool Vector2::operator != (const Vector2& v) const
{
	return x != v.x || y != v.y;
}

inline Vector2& Vector2::operator = (const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

inline Vector2& Vector2::operator += (const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vector2& Vector2::operator -= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline Vector2& Vector2::operator *= (float s)
{
	x *= s;
	y *= s;
	return *this;
}

inline Vector2& Vector2::operator /= (float s)
{
	x /= s;
	y /= s;
	return *this;
}

inline Vector2 operator+ (const Vector2& a, const Vector2& b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

inline Vector2 operator- (const Vector2& a, const Vector2& b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

inline Vector2 operator* (const Vector2& v, float s)
{
	return Vector2(v.x * s, v.y * s);
}

inline Vector2 operator/ (const Vector2& v, float s)
{
	return Vector2(v.x / s, v.y / s);
}

inline Vector2 operator* (float s, const Vector2& v)
{
	return Vector2(v.x * s, v.y * s);
}

// Vector3

inline float Vector3::Magnitude() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

inline float Vector3::SqrMagnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

inline Vector3 Vector3::Normalized() const
{
	return (*this) / Magnitude();
}

inline void Vector3::Normalize()
{
	(*this) = Normalized();
}

inline float Vector3::Angle(const Vector3& a, const Vector3& b)
{
	return acos(Vector3::Dot(a, b) / (a.Magnitude() * b.Magnitude())) * 180.0 / PI;
}

inline Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

inline float Vector3::Distance(const Vector3& a, const Vector3& b)
{
	return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}

inline float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return lhs.Magnitude() * rhs.Magnitude() * cos(Vector3::Angle(lhs, rhs) * PI / 180.0);
}

inline Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float t)
{
	t = std::min<float>(1.0, std::max<float>(0.0, t));
	return (1.0 - t) * a + t * b;
}

inline Vector3 Vector3::LerpUnclamped(const Vector3& a, const Vector3& b, float t)
{
	return (1.0 - t) * a + t * b;
}

inline Vector3 Vector3::Reflect(const Vector3& inDirection, const Vector3& inNormal)
{
	return -2.0 * Vector3::Dot(inDirection, inNormal) * inNormal + inDirection;
}

inline bool Vector3::operator == (const Vector3& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

inline bool Vector3::operator != (const Vector3& v) const
{
	return x != v.x || y != v.y || z != v.z;
}

inline Vector3& Vector3::operator= (const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

inline Vector3& Vector3::operator += (const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline Vector3& Vector3::operator -= (const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline Vector3& Vector3::operator *= (const float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

inline Vector3& Vector3::operator /= (const float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

inline Vector3 operator+ (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3 operator- (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector3 operator* (const Vector3& v, float s)
{
	return Vector3(v.x * s, v.y * s, v.z * s);
}

inline Vector3 operator/ (const Vector3& v, float s)
{
	return Vector3(v.x / s, v.y / s, v.z / s);
}

inline Vector3 operator* (float s, const Vector3& v)
{
	return Vector3(v.x * s, v.y * s, v.z * s);
}

// Quaternion

inline Vector3 Quaternion::EulerAngles() const
{
	Vector3 euler = Vector3();

	double sqw = w*w;
	double sqx = x*x;
	double sqy = y*y;
	double sqz = z*z;
	double test = 2.0 * (y*w - x*z);

	if (abs(test - 1.0) < 0.000001)
	{
		// heading = rotation about z-axis
		euler.z = (float)(-2.0*atan2(x, w));
		// bank = rotation about x-axis
		euler.x = 0;
		// attitude = rotation about y-axis
		euler.y = (float)(PI / 2.0);
	}
	else if (abs(test + 1.0) < 0.000001)
	{
		// heading = rotation about z-axis
		euler.z = (float)(2.0*atan2(x, w));
		// bank = rotation about x-axis
		euler.x = 0;
		// attitude = rotation about y-axis
		euler.y = (float)(PI / -2.0);
	}
	else
	{
		// heading = rotation about z-axis
		euler.z = (float)atan2(2.0 * (x*y + z*w), (sqx - sqy - sqz + sqw));
		// bank = rotation about x-axis
		euler.x = (float)atan2(2.0 * (y*z + x*w), (-sqx - sqy + sqz + sqw));
		// attitude = rotation about y-axis
		euler.y = (float)asin(std::min<float>(1.0, std::max<float>(-1.0, (float)test)));
	}

	return euler * (180.0 / PI);
}

inline Quaternion Quaternion::Normalized() const
{
	float n = x*x + y*y + z*z + w*w;

	if (n == 1)
		return *this;

	float inverseSqrt = 1 / sqrt(n);

	return (*this) * inverseSqrt;
}

inline void Quaternion::Normalize()
{
	float n = x*x + y*y + z*z + w*w;
	
	if (n == 1)
		return;
	
	float inverseSqrt = 1 / sqrt(n);
	x *= inverseSqrt;
	y *= inverseSqrt;
	z *= inverseSqrt;
	w *= inverseSqrt;
}

inline Quaternion Quaternion::Conjugate(const Quaternion& rotation)
{
	return rotation * Quaternion(-1, -1, -1, 1);
}

inline Quaternion Quaternion::Euler(const Vector3& euler)
{
	double angle;

	angle = euler.x * PI / 180 * 0.5;
	double sr = sin(angle);
	double cr = cos(angle);

	angle = euler.y * PI / 180 * 0.5;
	double sp = sin(angle);
	double cp = cos(angle);

	angle = euler.z * PI / 180 * 0.5;
	double sy = sin(angle);
	double cy = cos(angle);

	double cpcy = cp * cy;
	double spcy = sp * cy;
	double cpsy = cp * sy;
	double spsy = sp * sy;

	Quaternion quaternion = Quaternion((float)(sr * cpcy - cr * spsy),
		(float)(cr * spcy + sr * cpsy),
		(float)(cr * cpsy - sr * spcy),
		(float)(cr * cpcy + sr * spsy));
	quaternion.Normalize();

	return quaternion;
}

inline Quaternion Quaternion::Inverse(const Quaternion& rotation)
{
	return Quaternion::Conjugate(rotation.Normalized());
}

inline bool Quaternion::operator == (const Quaternion& q) const
{
	return x == q.x && y == q.y && z == q.z && w == q.w;
}

inline bool Quaternion::operator != (const Quaternion& q) const
{
	return x != q.x || y != q.y || z != q.z || w != q.w;
}

inline Quaternion& Quaternion::operator= (const Quaternion& q)
{
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
	return *this;
}

inline Quaternion& Quaternion::operator += (const Quaternion& q)
{
	x += q.x;
	y += q.y;
	z += q.z;
	w += q.w;
	return *this;
}

inline Quaternion& Quaternion::operator -= (const Quaternion& q)
{
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
	return *this;
}

inline Quaternion& Quaternion::operator *= (const Quaternion& q)
{
	Quaternion quaternion = Quaternion(
		+x * q.w + y*q.z - z*q.y + w*q.x,
		-x * q.z + y*q.w + z*q.x + w*q.y,
		+x * q.y - y*q.x + z*q.w + w*q.z,
		-x * q.x - y*q.y - z*q.z + w*q.w);
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
	return *this;
}

inline Quaternion& Quaternion::operator *= (float s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}

inline Quaternion& Quaternion::operator /= (const Quaternion& q)
{
	Quaternion inverse = Quaternion::Inverse(q);

	Quaternion quaternion = Quaternion(
		+x * inverse.w + y*inverse.z - z*inverse.y + w*inverse.x,
		-x * inverse.z + y*inverse.w + z*inverse.x + w*inverse.y,
		+x * inverse.y - y*inverse.x + z*inverse.w + w*inverse.z,
		-x * inverse.x - y*inverse.y - z*inverse.z + w*inverse.w);
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
	return *this;
}

inline Quaternion operator+ (const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Quaternion operator- (const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Quaternion operator* (const Quaternion& a, const Quaternion& b)
{
	return Quaternion(
		+a.x * b.w + a.y*b.z - a.z*b.y + a.w*b.x,
		-a.x * b.z + a.y*b.w + a.z*b.x + a.w*b.y,
		+a.x * b.y - a.y*b.x + a.z*b.w + a.w*b.z,
		-a.x * b.x - a.y*b.y - a.z*b.z + a.w*b.w);
}

inline Quaternion operator* (const Quaternion& q, float s)
{
	return Quaternion(q.x * s, q.y * s, q.z * s, q.w * s);
}

inline Matrix4x4 Matrix4x4::Frustum(float xmin, float xmax, float ymin, float ymax, float zNear, float zFar)
{
	Matrix4x4 m = Matrix4x4::Zero;

	float doubleznear = 2.0f * zNear;
	float one_deltax = 1.0f / (xmax - xmin);
	float one_deltay = 1.0f / (ymax - ymin);
	float one_deltaz = 1.0f / (zFar - zNear);

	m._m[0][0] = doubleznear * one_deltax;
	m._m[1][1] = doubleznear * one_deltay;
	m._m[0][2] = (xmax + xmin) * one_deltax;
	m._m[1][2] = (ymax + ymin) * one_deltay;
	m._m[2][2] = -(zFar + zNear) * one_deltaz;
	m._m[3][2] = -1.0f;
	m._m[2][3] = -(zFar * doubleznear) * one_deltaz;

	return m;
}

inline Quaternion operator/ (const Quaternion& a, const Quaternion& b)
{
	Quaternion inverse = Quaternion::Inverse(b);

	return Quaternion(
		+a.x * inverse.w + a.y*inverse.z - a.z*inverse.y + a.w*inverse.x,
		-a.x * inverse.z + a.y*inverse.w + a.z*inverse.x + a.w*inverse.y,
		+a.x * inverse.y - a.y*inverse.x + a.z*inverse.w + a.w*inverse.z,
		-a.x * inverse.x - a.y*inverse.y - a.z*inverse.z + a.w*inverse.w);
}

// Matrix4x4

inline float Matrix4x4::Determinant() const
{
	return
		_ms[3] * _ms[6] * _ms[9] * _ms[12] - _ms[2] * _ms[7] * _ms[9] * _ms[12] - _ms[3] * _ms[5] * _ms[10] * _ms[12] + _ms[1] * _ms[7] * _ms[10] * _ms[12] +
		_ms[2] * _ms[5] * _ms[11] * _ms[12] - _ms[1] * _ms[6] * _ms[11] * _ms[12] - _ms[3] * _ms[6] * _ms[8] * _ms[13] + _ms[2] * _ms[7] * _ms[8] * _ms[13] +
		_ms[3] * _ms[4] * _ms[10] * _ms[13] - _ms[0] * _ms[7] * _ms[10] * _ms[13] - _ms[2] * _ms[4] * _ms[11] * _ms[13] + _ms[0] * _ms[6] * _ms[11] * _ms[13] +
		_ms[3] * _ms[5] * _ms[8] * _ms[14] - _ms[1] * _ms[7] * _ms[8] * _ms[14] - _ms[3] * _ms[4] * _ms[9] * _ms[14] + _ms[0] * _ms[7] * _ms[9] * _ms[14] +
		_ms[1] * _ms[4] * _ms[11] * _ms[14] - _ms[0] * _ms[5] * _ms[11] * _ms[14] - _ms[2] * _ms[5] * _ms[8] * _ms[15] + _ms[1] * _ms[6] * _ms[8] * _ms[15] +
		_ms[2] * _ms[4] * _ms[9] * _ms[15] - _ms[0] * _ms[6] * _ms[9] * _ms[15] - _ms[1] * _ms[4] * _ms[10] * _ms[15] + _ms[0] * _ms[5] * _ms[10] * _ms[15];
}

inline Matrix4x4 Matrix4x4::Inverse(const Matrix4x4& m)
{
	Matrix4x4 r;
	r._ms[0] = m._ms[6]*m._ms[11]*m._ms[13] - m._ms[7]*m._ms[10]*m._ms[13] + m._ms[7]*m._ms[9]*m._ms[14] - m._ms[5]*m._ms[11]*m._ms[14] - m._ms[6]*m._ms[9]*m._ms[15] + m._ms[5]*m._ms[10]*m._ms[15];
	r._ms[1] = m._ms[3]*m._ms[10]*m._ms[13] - m._ms[2]*m._ms[11]*m._ms[13] - m._ms[3]*m._ms[9]*m._ms[14] + m._ms[1]*m._ms[11]*m._ms[14] + m._ms[2]*m._ms[9]*m._ms[15] - m._ms[1]*m._ms[10]*m._ms[15];
	r._ms[2] = m._ms[2]*m._ms[7]*m._ms[13] - m._ms[3]*m._ms[6]*m._ms[13] + m._ms[3]*m._ms[5]*m._ms[14] - m._ms[1]*m._ms[7]*m._ms[14] - m._ms[2]*m._ms[5]*m._ms[15] + m._ms[1]*m._ms[6]*m._ms[15];
	r._ms[3] = m._ms[3]*m._ms[6]*m._ms[9] - m._ms[2]*m._ms[7]*m._ms[9] - m._ms[3]*m._ms[5]*m._ms[10] + m._ms[1]*m._ms[7]*m._ms[10] + m._ms[2]*m._ms[5]*m._ms[11] - m._ms[1]*m._ms[6]*m._ms[11];
	r._ms[4] = m._ms[7]*m._ms[10]*m._ms[12] - m._ms[6]*m._ms[11]*m._ms[12] - m._ms[7]*m._ms[8]*m._ms[14] + m._ms[4]*m._ms[11]*m._ms[14] + m._ms[6]*m._ms[8]*m._ms[15] - m._ms[4]*m._ms[10]*m._ms[15];
	r._ms[5] = m._ms[2]*m._ms[11]*m._ms[12] - m._ms[3]*m._ms[10]*m._ms[12] + m._ms[3]*m._ms[8]*m._ms[14] - m._ms[0]*m._ms[11]*m._ms[14] - m._ms[2]*m._ms[8]*m._ms[15] + m._ms[0]*m._ms[10]*m._ms[15];
	r._ms[6] = m._ms[3]*m._ms[6]*m._ms[12] - m._ms[2]*m._ms[7]*m._ms[12] - m._ms[3]*m._ms[4]*m._ms[14] + m._ms[0]*m._ms[7]*m._ms[14] + m._ms[2]*m._ms[4]*m._ms[15] - m._ms[0]*m._ms[6]*m._ms[15];
	r._ms[7] = m._ms[2]*m._ms[7]*m._ms[8] - m._ms[3]*m._ms[6]*m._ms[8] + m._ms[3]*m._ms[4]*m._ms[10] - m._ms[0]*m._ms[7]*m._ms[10] - m._ms[2]*m._ms[4]*m._ms[11] + m._ms[0]*m._ms[6]*m._ms[11];
	r._ms[8] = m._ms[5]*m._ms[11]*m._ms[12] - m._ms[7]*m._ms[9]*m._ms[12] + m._ms[7]*m._ms[8]*m._ms[13] - m._ms[4]*m._ms[11]*m._ms[13] - m._ms[5]*m._ms[8]*m._ms[15] + m._ms[4]*m._ms[9]*m._ms[15];
	r._ms[9] = m._ms[3]*m._ms[9]*m._ms[12] - m._ms[1]*m._ms[11]*m._ms[12] - m._ms[3]*m._ms[8]*m._ms[13] + m._ms[0]*m._ms[11]*m._ms[13] + m._ms[1]*m._ms[8]*m._ms[15] - m._ms[0]*m._ms[9]*m._ms[15];
	r._ms[10] = m._ms[1]*m._ms[7]*m._ms[12] - m._ms[3]*m._ms[5]*m._ms[12] + m._ms[3]*m._ms[4]*m._ms[13] - m._ms[0]*m._ms[7]*m._ms[13] - m._ms[1]*m._ms[4]*m._ms[15] + m._ms[0]*m._ms[5]*m._ms[15];
	r._ms[11] = m._ms[3]*m._ms[5]*m._ms[8] - m._ms[1]*m._ms[7]*m._ms[8] - m._ms[3]*m._ms[4]*m._ms[9] + m._ms[0]*m._ms[7]*m._ms[9] + m._ms[1]*m._ms[4]*m._ms[11] - m._ms[0]*m._ms[5]*m._ms[11];
	r._ms[12] = m._ms[6]*m._ms[9]*m._ms[12] - m._ms[5]*m._ms[10]*m._ms[12] - m._ms[6]*m._ms[8]*m._ms[13] + m._ms[4]*m._ms[10]*m._ms[13] + m._ms[5]*m._ms[8]*m._ms[14] - m._ms[4]*m._ms[9]*m._ms[14];
	r._ms[13] = m._ms[1]*m._ms[10]*m._ms[12] - m._ms[2]*m._ms[9]*m._ms[12] + m._ms[2]*m._ms[8]*m._ms[13] - m._ms[0]*m._ms[10]*m._ms[13] - m._ms[1]*m._ms[8]*m._ms[14] + m._ms[0]*m._ms[9]*m._ms[14];
	r._ms[14] = m._ms[2]*m._ms[5]*m._ms[12] - m._ms[1]*m._ms[6]*m._ms[12] - m._ms[2]*m._ms[4]*m._ms[13] + m._ms[0]*m._ms[6]*m._ms[13] + m._ms[1]*m._ms[4]*m._ms[14] - m._ms[0]*m._ms[5]*m._ms[14];
	r._ms[15] = m._ms[1]*m._ms[6]*m._ms[8] - m._ms[2]*m._ms[5]*m._ms[8] + m._ms[2]*m._ms[4]*m._ms[9] - m._ms[0]*m._ms[6]*m._ms[9] - m._ms[1]*m._ms[4]*m._ms[10] + m._ms[0]*m._ms[5]*m._ms[10];
	r *= 1.0f / m.Determinant();
	return r;
}

inline Matrix4x4 Matrix4x4::Rotation(const Quaternion& q)
{
	Matrix4x4 r;

	const float x2 = q.x + q.x;  const float y2 = q.y + q.y;  const float z2 = q.z + q.z;
	const float xx = q.x * x2;   const float xy = q.x * y2;   const float xz = q.x * z2;
	const float yy = q.y * y2;   const float yz = q.y * z2;   const float zz = q.z * z2;
	const float wx = q.w * x2;   const float wy = q.w * y2;   const float wz = q.w * z2;

	r._m[0][0] = 1.0f - (yy + zz);
	r._m[1][0] = xy - wz;
	r._m[2][0] = xz + wy;
	r._m[3][0] = q.x;
	r._m[0][1] = xy + wz;
	r._m[1][1] = 1.0f - (xx + zz);
	r._m[2][1] = yz - wx;
	r._m[3][1] = q.y;
	r._m[0][2] = xz - wy;
	r._m[1][2] = yz + wx;
	r._m[2][2] = 1.0f - (xx + yy);
	r._m[3][2] = q.z;
	r._m[0][3] = 0.0f;
	r._m[1][3] = 0.0f;
	r._m[2][3] = 0.0f;
	r._m[3][3] = 1.0f;

	return r;
}

inline Matrix4x4 Matrix4x4::Scale(const Vector3& s)
{
	Matrix4x4 r = Matrix4x4::Identity;
	r._m[0][0] = s.x;
	r._m[1][1] = s.y;
	r._m[2][2] = s.z;
	return r;
}

inline Matrix4x4 Matrix4x4::Scale(float s)
{
	Matrix4x4 r = Matrix4x4::Identity;
	r._m[0][0] = r._m[1][1] =  r._m[2][2] = s;
	return r;
}

inline Matrix4x4 Matrix4x4::Translate(const Vector3& pos)
{
	Matrix4x4 r = Matrix4x4::Identity;
	r._m[0][3] = pos.x;
	r._m[1][3] = pos.y;
	r._m[2][3] = pos.z;
	return r;
}

inline Matrix4x4 Matrix4x4::Perspective(float fov, float aspect, float zNear, float zFar)
{
	float xmax = zNear * tan(fov / 2);
	float xmin = -xmax;

	float ymax = xmax / aspect;
	float ymin = -ymax;

	return Matrix4x4::Frustum(xmin, xmax, ymin, ymax, zNear, zFar);
}

inline Matrix4x4 Matrix4x4::Transpose(const Matrix4x4& m)
{
	Matrix4x4 r;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; i++)
		{
			r._m[i][j] = m._m[j][i];
		}
	}
	return r;
}

inline Matrix4x4 Matrix4x4::TRS(const Vector3& pos, const Quaternion& q, const Vector3& s)
{
	return Matrix4x4::Scale(s) * Matrix4x4::Rotation(q) * Matrix4x4::Translate(pos);
}

inline bool Matrix4x4::operator == (const Matrix4x4& m) const
{
	return _11 == m._11 && _12 == m._12 && _13 == m._13 && _14 == m._14 &&
		_21 == m._21 && _22 == m._22 && _23 == m._23 && _24 == m._24 &&
		_31 == m._31 && _32 == m._32 && _33 == m._33 && _34 == m._34 &&
		_41 == m._41 && _42 == m._42 && _43 == m._43 && _44 == m._44;
}

inline bool Matrix4x4::operator != (const Matrix4x4& m) const
{
	return _11 != m._11 || _12 != m._12 || _13 != m._13 || _14 != m._14 ||
		_21 != m._21 || _22 != m._22 || _23 != m._23 || _24 != m._24 ||
		_31 != m._31 || _32 != m._32 || _33 != m._33 || _34 != m._34 ||
		_41 != m._41 || _42 != m._42 || _43 != m._43 || _44 != m._44;
}

inline Matrix4x4& Matrix4x4::operator= (const Matrix4x4& m)
{
	_11 = m._11;
	_12 = m._12;
	_13 = m._13;
	_14 = m._14;
	_21 = m._21;
	_22 = m._22;
	_23 = m._23;
	_24 = m._24;
	_31 = m._31;
	_32 = m._32;
	_33 = m._33;
	_34 = m._34;
	_41 = m._41;
	_42 = m._42;
	_43 = m._43;
	_44 = m._44;
	return *this;
}

inline Matrix4x4& Matrix4x4::operator *= (const Matrix4x4& m)
{
	Matrix4x4 r;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			r._m[row][col] = 0;
			for (int inner = 0; inner < 4; inner++) {
				r._m[row][col] += _m[row][inner] * m._m[inner][col];
			}
		}
	}
	*this = r;
	return *this;
}

inline Matrix4x4& Matrix4x4::operator *= (float s)
{
	_11 *= s;
	_12 *= s;
	_13 *= s;
	_14 *= s;
	_21 *= s;
	_22 *= s;
	_23 *= s;
	_24 *= s;
	_31 *= s;
	_32 *= s;
	_33 *= s;
	_34 *= s;
	_41 *= s;
	_42 *= s;
	_43 *= s;
	_44 *= s;
	return *this;
}

inline Matrix4x4 operator* (const Matrix4x4& a, const Matrix4x4& b)
{
	Matrix4x4 r;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			r._m[row][col] = 0;
			for (int inner = 0; inner < 4; inner++) {
				r._m[row][col] += a._m[row][inner] * b._m[inner][col];
			}
		}
	}
	return r;
}

inline Matrix4x4 operator* (const Matrix4x4& m, float s)
{
	Matrix4x4 r;
	r._11 = m._11 * s;
	r._12 = m._12 * s;
	r._13 = m._13 * s;
	r._14 = m._14 * s;
	r._21 = m._21 * s;
	r._22 = m._22 * s;
	r._23 = m._23 * s;
	r._24 = m._24 * s;
	r._31 = m._31 * s;
	r._32 = m._32 * s;
	r._33 = m._33 * s;
	r._34 = m._34 * s;
	r._41 = m._41 * s;
	r._42 = m._42 * s;
	r._43 = m._43 * s;
	r._44 = m._44 * s;
	return r;
}

// Color

inline Color Color::Lerp(const Color& a, const Color& b, float t)
{
	t = std::min<float>(1.0, std::max<float>(0.0, t));
	return (1.0 - t) * a + t * b;
}

inline Color Color::LerpUnclamped(const Color& a, const Color& b, float t)
{
	return (1.0 - t) * a + t * b;
}

inline bool Color::operator == (const Color& c) const
{
	return r == c.r && g == c.g && b == c.b && a == c.a;
}

inline bool Color::operator != (const Color& c) const
{
	return r != c.r || g != c.g || b != c.b || a != c.a;
}

inline Color Color::operator- () const
{
	return Color(-r, -g, -b, -a);
}

inline Color& Color::operator= (const Color& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
	return *this;
}

inline Color& Color::operator += (const Color& c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	a += c.a;
	return *this;
}

inline Color& Color::operator -= (const Color& c)
{
	r -= c.r;
	g -= c.g;
	b -= c.b;
	a -= c.a;
	return *this;
}

inline Color& Color::operator *= (const Color& c)
{
	r *= c.r;
	g *= c.g;
	b *= c.b;
	a *= c.a;
	return *this;
}

inline Color& Color::operator *= (float s)
{
	r *= s;
	g *= s;
	b *= s;
	a *= s;
	return *this;
}

inline Color& Color::operator /= (const Color& c)
{
	r /= c.r;
	g /= c.g;
	b /= c.b;
	a /= c.a;
	return *this;
}

inline Color operator+ (const Color& a, const Color& b)
{
	return Color(a.r + b.r, a.g + b.g, a.b + b.b, a.a + b.a);
}

inline Color operator- (const Color& a, const Color& b)
{
	return Color(a.r - b.r, a.g - b.g, a.b - b.b, a.a - b.a);
}

inline Color operator* (const Color& a, const Color& b)
{
	return Color(a.r * b.r, a.g * b.g, a.b * b.b, a.a * b.a);
}

inline Color operator* (const Color& c, float s)
{
	return Color(c.r * s, c.g * s, c.b * s, c.a * s);
}

inline Color operator/ (const Color& a, const Color& b)
{
	return Color(a.r / b.r, a.g / b.g, a.b / b.b, a.a / b.a);
}

inline Color operator* (float s, const Color& c)
{
	return Color(c.r * s, c.g * s, c.b * s, c.a * s);
}