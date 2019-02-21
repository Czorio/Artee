#include "Precomp.h"

#if EXP_SIMD_VEC
vec3 vec3::operator-() const
{
	return vec3(_mm_mul_ps(cell, _mm_set1_ps(-1.f)));
}

vec3 vec3::operator+(const vec3 & operand) const
{
	return vec3(_mm_add_ps(cell, operand.cell));
}

vec3 vec3::operator-(const vec3 & operand) const
{
	return vec3(_mm_sub_ps(cell, operand.cell));
}

vec3 vec3::operator*(const vec3 & operand) const
{
	return vec3(_mm_mul_ps(cell, operand.cell));
}

void vec3::operator-=(const vec3 & a)
{
	cell = _mm_sub_ps(cell, a.cell);
}

void vec3::operator+=(const vec3 & a)
{
	cell = _mm_add_ps(cell, a.cell);
}

void vec3::operator*=(const vec3 & a)
{
	cell = _mm_mul_ps(cell, a.cell);
}

void vec3::operator*=(const float a)
{
	cell = _mm_mul_ps(cell, _mm_set1_ps(a));
}

inline float vec3::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

inline float vec3::sqrLentgh() const
{
	return x * x + y * y + z * z;
}

inline vec3 vec3::normalized() const
{
	float r = 1.0f / length();
	return vec3(x * r, y * r, z * r);
}

inline void vec3::normalize()
{
	float r = 1.0f / length();
	x *= r; y *= r; z *= r;
}

inline vec3 vec3::normalize(const vec3 v)
{
	return v.normalized();
}

inline vec3 vec3::cross(const vec3 & operand) const
{
	return vec3(y * operand.z - z * operand.y, z * operand.x - x * operand.z, x * operand.y - y * operand.x);
}

inline float vec3::dot(const vec3 & operand) const
{
	return x * operand.x + y * operand.y + z * operand.z;
}
#else
vec3 vec3::operator-() const
{
	return vec3(-x, -y, -z);
}

vec3 vec3::operator+(const vec3 & addOperand) const
{
	return vec3(x + addOperand.x, y + addOperand.y, z + addOperand.z);
}

vec3 vec3::operator-(const vec3 & operand) const
{
	return vec3(x - operand.x, y - operand.y, z - operand.z);
}

vec3 vec3::operator*(const vec3 & operand) const
{
	return vec3(x * operand.x, y * operand.y, z * operand.z);
}

void vec3::operator-=(const vec3 & a)
{
	x -= a.x; y -= a.y; z -= a.z;
}

void vec3::operator+=(const vec3 & a)
{
	x += a.x; y += a.y; z += a.z;
}

void vec3::operator*=(const vec3 & a)
{
	x *= a.x; y *= a.y; z *= a.z;
}

void vec3::operator*=(const float a)
{
	x *= a; y *= a; z *= a;
}

inline float vec3::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

inline float vec3::sqrLentgh() const
{
	return x * x + y * y + z * z;
}

inline vec3 vec3::normalized() const
{
	float r = 1.0f / length(); return vec3(x * r, y * r, z * r);
}

inline void vec3::normalize()
{
	float r = 1.0f / length(); x *= r; y *= r; z *= r;
}

inline vec3 vec3::normalize(const vec3 v)
{
	return v.normalized();
}

inline vec3 vec3::cross(const vec3 & operand) const
{
	return vec3(y * operand.z - z * operand.y, z * operand.x - x * operand.z, x * operand.y - y * operand.x);
}

inline float vec3::dot(const vec3 & operand) const
{
	return x * operand.x + y * operand.y + z * operand.z;
}
#endif
