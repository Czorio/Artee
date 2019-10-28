#include "Ray.h"

Ray::Ray()
{
	origin = direction = Vec3f();
}

Ray::Ray(const Vec3f& origin, const Vec3f& direction)
{
	this->origin = origin;
	this->direction = direction;
}

Ray::~Ray()
{
}

Vec3f Ray::operator()(float t) const
{
	return origin + direction * t;
}