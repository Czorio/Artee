#pragma once
#include "Vec3f.h"
#include <limits>

struct HitRecord
{
	// Rendering stuff
	bool insideHit;
	float distance = std::numeric_limits<float>::max();

	// World stuff
	Vec3f position;
	Vec3f normal;

	// Material stuff
	Vec3f color;
	float emission;
	float roughness;
	float transparency;
	float refractive;
};
