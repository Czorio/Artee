#include "Sphere.h"

#include <cmath>

Sphere::Sphere()
{
	origin_ = Vec3f();
	radius_ = 0.f;
	r2_ = 0.f;
}

Sphere::Sphere(const Vec3f& origin, const float radius)
{
	this->origin_ = origin;
	this->radius_ = radius;
	r2_ = radius * radius;
}

bool Sphere::hit(const Ray& r, HitRecord& hit)
{
	// ABC Formula for ray-sphere intersection
	const auto a = Dot(r.direction, r.direction);
	const auto b = 2.f * Dot(r.direction, r.origin - origin_);
	const auto c = Dot(r.origin - origin_, r.origin - origin_) - r2_;
	const auto d = (b * b) - 4 * a * c;

	if (d < 0)
	{
		// No hit, womp womp
		// We do get to skip the sqrt now, though
		return false;
	}
	// Yes hit, calculate distances from origin
	const auto divisor = (1.f / 2.f) * a;

	// t1 is always <t2, due to the subtraction
	// If t1 is more than 0, i.e. in front of the ray,
	// then we can simply forget about calculating t2
	const auto t1 = (-b - sqrtf(d)) * divisor;
	if (t1 > 0.0f)
	{
		hit.distance = t1;
		hit.position = r(t1);
		hit.normal = hit.position - origin_;

		return true;
	}

	const auto t2 = (-b + sqrtf(d)) * divisor;
	if (t2 > 0.0f)
	{
		hit.distance = t2;
		hit.position = r(t2);
		hit.normal = hit.position - origin_;

		return true;
	}

	// Both intersection points were behind the ray
	return false;
}
