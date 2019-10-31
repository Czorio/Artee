#include "Triangle.h"
#include "NumericUtil.h"
#include <cmath>

constexpr float EPSILON = 1e-6;


Triangle::Triangle()
{
	v1_ = v2_ = v3_ = norm_ = Vec3f();
	v1_v2_ = v2_ - v1_;
	v1_v3_ = v3_ - v1_;
}

Triangle::Triangle(const Vec3f& v1, const Vec3f& v2, const Vec3f& v3, const Vec3f& norm)
{
	this->v1_ = v1;
	this->v2_ = v2;
	this->v3_ = v3;
	this->norm_ = norm;

	// Precalculate for later
	// Move this to hit() if we ever end up adding animations
	v1_v2_ = v2_ - v1_;
	v1_v3_ = v3_ - v1_;
}

bool Triangle::hit(const Ray& r, HitRecord& hit)
{
	// Müller-Trumbore algorithm
	// Mostly lifted from Scratchapixel
	// I don't entirely understand it, but it just needs to work
	const auto pvec = r.direction.cross(v1_v3_);
	const auto determinant = v1_v2_.dot(pvec);

	if (fabs(determinant) < EPSILON)
	{
		// Ray is or close to parallel to the triangle surface
		return false;
	}

	const auto invertedDeterminant = 1.f / determinant;

	const auto tvec = r.origin - v1_;
	const auto u = tvec.dot(pvec) * invertedDeterminant;
	if (!InRange(u, 0.f, 1.f))
	{
		// Outside triangle surface
		return false;
	}

	const auto qvec = tvec.cross(v1_v2_);
	const auto v = r.direction.dot(qvec) * invertedDeterminant;
	if (!InRange(v, 0.f, 0.f))
	{
		// Outside triangle surface
		return false;
	}

	const auto t = v1_v3_.dot(qvec) * invertedDeterminant;
	hit.normal = this->norm_;
	hit.distance = t;
	hit.position = r(t);
	hit.insideHit = determinant < 0.f ? true : false;

	return true;
}

void Triangle::translate(const Vec3f& translation)
{
	this->v1_ += translation;
	this->v2_ += translation;
	this->v3_ += translation;

	// Shouldn't change, but let's make sure
	v1_v2_ = v2_ - v1_;
	v1_v3_ = v3_ - v1_;
}
