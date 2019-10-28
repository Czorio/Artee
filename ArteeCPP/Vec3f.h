#pragma once
#include <nmmintrin.h>

class Vec3f
{
public:
	Vec3f();
	Vec3f(const float broad);
	Vec3f(const float x, const float y, const float z);
	Vec3f(const __m128& vector);
	~Vec3f();

	Vec3f operator +(const Vec3f& b) const;
	void operator +=(const Vec3f& b);
	Vec3f operator -(const Vec3f& b) const;
	void operator -=(const Vec3f& b);
	Vec3f operator *(const float f) const;
	Vec3f operator *(const Vec3f& b) const;
	Vec3f operator /(const float f) const;
	float operator [](int pos) const;

	float dot(const Vec3f& b) const;
	Vec3f cross(const Vec3f& b) const;

	float getLength() const;
	float getSquaredLength() const;

	void normalize();
	Vec3f normalized() const;
private:
	union
	{
		__m128 _vector;
		float xyz[4];
	};
};

Vec3f Normalize(const Vec3f& a);
float Dot(const Vec3f& a, const Vec3f& b);
Vec3f Cross(const Vec3f& a, const Vec3f& b);
float LengthOfVector(const Vec3f& a);