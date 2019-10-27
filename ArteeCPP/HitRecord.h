#pragma once
#include "Vec3f.h"

struct HitRecord
{
	// Rendering stuff
	bool insideHit;
	
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

