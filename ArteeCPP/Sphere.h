#pragma once
#include "Primitive.h"

class Sphere final : public Primitive
{
public:
	Sphere();
	Sphere(const Vec3f& origin, float radius);
	~Sphere() = default;

	bool hit(const Ray& r, HitRecord& hit) override;

private:
	Vec3f origin_;
	float radius_;
	float r2_;
};
