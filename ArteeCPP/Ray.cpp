#include "Ray.h"

Ray::Ray()
{
	origin = direction = Vec3f();
}

Ray::Ray(Vec3f origin, Vec3f direction)
{
	this->origin = origin;
	this->direction = direction;
}

Ray::~Ray()
{
}

Vec3f Ray::operator()(float t)
{
	return origin + direction * t;
}
