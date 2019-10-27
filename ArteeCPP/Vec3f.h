#pragma once
#include <nmmintrin.h>

class Vec3f
{
public:
	Vec3f();
	Vec3f(float broad);
	Vec3f(float x, float y, float z);
	Vec3f(__m128 vector);
	~Vec3f();

	Vec3f operator +(Vec3f b);
	void operator +=(Vec3f b);
	Vec3f operator -(Vec3f b);
	void operator -=(Vec3f b);
	Vec3f operator *(float f);
	Vec3f operator *(Vec3f b);
	Vec3f operator /(float f);
	float operator [](int pos);

	float dot(Vec3f b);
	Vec3f cross(Vec3f b);

	float getLength();
	float getSquaredLength();

	void normalize();
	Vec3f normalized();
private:
	union
	{
		__m128 _vector;
		float xyz[4];
	};
};

Vec3f Normalize(Vec3f a);
float Dot(Vec3f a, Vec3f b);
Vec3f Cross(Vec3f a, Vec3f b);
float LengthOfVector(Vec3f a);