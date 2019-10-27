#pragma once
#include "Vec3f.h"

struct Ray
{
	Ray();
	Ray(Vec3f origin, Vec3f direction);
	~Ray();

	Vec3f operator ()(float t);

	Vec3f origin;
	Vec3f direction;
};

