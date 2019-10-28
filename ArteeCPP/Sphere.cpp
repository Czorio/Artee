#include "Sphere.h"

#include <math.h>

Sphere::Sphere()
{
	origin = Vec3f();
	radius = 0.f;
	r2 = 0.f;
}

Sphere::Sphere(Vec3f origin, float radius)
{
	this->origin = origin;
	this->radius = radius;
	r2 = radius * radius;
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray& r, HitRecord& hit)
{
	// ABC Formula for ray-sphere intersection
	float a = Dot(r.direction, r.direction);
	float b = 2.f * Dot(r.direction, r.origin - origin);
	float c = Dot(r.origin - origin, r.origin - origin) - r2;
	float d = (b * b) - 4 * a * c;

	if (d < 0)
	{
		// No hit, womp womp
		// We do get to skip the sqrt now, though
		return false;
	}
	else
	{
		// Yes hit, calculate distances from origin
		float divisor = 1 / 2 * a;
		
		// t1 is always <t2, due to the subtraction
		// If t1 is more than 0, i.e. in front of the ray,
		// then we can simply forget about calculating t2
		float t1 = (-b - sqrtf(d)) * divisor;
		if (t1 > 0.0f)
		{
			hit.distance = t1;
			hit.position = r(t1);
			hit.normal = hit.position - origin;

			return true;
		}

		float t2 = (-b + sqrtf(d)) * divisor;
		if (t2 > 0.0f)
		{
			hit.distance = t2;
			hit.position = r(t2);
			hit.normal = hit.position - origin;

			return true;
		}

		// Both intersection points were behind the ray
		return false;
	}
}
