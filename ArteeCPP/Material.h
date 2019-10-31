#pragma once
#include "Vec3f.h"

class Material
{
public:
	Material();
	~Material() = default;

	Vec3f colourAt(float u, float v) const;

private:
	bool solid_colour_;
	Vec3f colour_;
};
