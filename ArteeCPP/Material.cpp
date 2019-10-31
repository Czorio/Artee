#include "Material.h"

Material::Material()
{
	solid_colour_ = true;
	colour_ = Vec3f();
}

Vec3f Material::colourAt(float u, float v) const
{
	if (solid_colour_)
	{
		return colour_;
	}
	return colour_;
}
