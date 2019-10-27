#include "Vec3f.h"
#include <math.h>

Vec3f::Vec3f()
{
	xyz[0] = 0.f;
	xyz[1] = 0.f;
	xyz[2] = 0.f;
	xyz[3] = 0.f;
}

Vec3f::Vec3f(float broad)
{
	xyz[0] = broad;
	xyz[1] = broad;
	xyz[2] = broad;
	xyz[3] = 0.f;
}

Vec3f::Vec3f(float x, float y, float z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
	xyz[3] = 0.f;
}

Vec3f::Vec3f(__m128 vector)
{
	_vector = vector;
}

Vec3f::~Vec3f()
{
}

Vec3f Vec3f::operator+(Vec3f b)
{
	return Vec3f(_mm_add_ps(_vector, b._vector));
}

void Vec3f::operator+=(Vec3f b)
{
	_vector = _mm_add_ps(_vector, b._vector);
}

Vec3f Vec3f::operator-(Vec3f b)
{
	return Vec3f(_mm_sub_ps(_vector, b._vector));
}

void Vec3f::operator-=(Vec3f b)
{
	_vector = _mm_sub_ps(_vector, b._vector);
}

Vec3f Vec3f::operator*(float f)
{
	return Vec3f(_mm_mul_ps(_vector, _mm_set_ps(f, f, f, f)));
}

Vec3f Vec3f::operator*(Vec3f b)
{
	return Vec3f(_mm_mul_ps(_vector, b._vector));
}

Vec3f Vec3f::operator/(float f)
{
	return Vec3f(_mm_div_ps(_vector, _mm_set_ps(f, f, f, f)));
}

float Vec3f::operator[](int pos)
{
	return xyz[pos];
}

float Vec3f::dot(Vec3f b)
{
	// Dot(A, B) = (A.x * B.x) + (A.y * B.y) + (A.z * B.z)
	Vec3f c = Vec3f(_mm_mul_ps(_vector, b._vector));
	return c[0] + c[1] + c[2] + c[3];
}

Vec3f Vec3f::cross(Vec3f b)
{
	// Cross(A, B) = [(A.y * B.z - A.z * B.y),
	//                (A.z * B.x - A.x * B.z),
	//                (A.x * B.y - A.y * B.x)]
	// TODO: See if we can vectorize this
	float x = xyz[1] * b[2] - xyz[2] * b[1];
	float y = xyz[2] * b[0] - xyz[0] * b[2];
	float z = xyz[0] * b[1] - xyz[1] * b[0];
	return Vec3f(x, y, z);
}

float Vec3f::getLength()
{
	// Contains a sqrt, is costly
	Vec3f c = Vec3f(_mm_mul_ps(_vector, _vector));
	return sqrtf(c[0] + c[1] + c[2]);
}

float Vec3f::getSquaredLength()
{
	// No sqrt, cheaper
	Vec3f c = Vec3f(_mm_mul_ps(_vector, _vector));
	return c[0] + c[1] + c[2];
}

void Vec3f::normalize()
{
	float l = getLength();
	_vector = _mm_div_ps(_vector, _mm_set_ps(l, l, l, l));
}

Vec3f Vec3f::normalized()
{
	float l = getLength();
	return Vec3f(_mm_div_ps(_vector, _mm_set_ps(l, l, l, l)));
}

Vec3f Normalize(Vec3f a)
{
	return a.normalized();
}

float Dot(Vec3f a, Vec3f b)
{
	return a.dot(b);
}

Vec3f Cross(Vec3f a, Vec3f b)
{
	return a.cross(b);
}

float LengthOfVector(Vec3f a)
{
	return a.getLength();
}
