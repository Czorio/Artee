#pragma once
#include "Vec3f.h"

struct Ray
{
	Ray();
	Ray(const Vec3f& origin, const Vec3f& direction);
	~Ray();

	Vec3f operator ()(float t) const;

	Vec3f origin;
	Vec3f direction;
};
