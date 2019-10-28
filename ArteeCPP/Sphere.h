#pragma once
#include "Primitive.h"

class Sphere : public Primitive
{
public:
	Sphere();
	Sphere(Vec3f origin, float radius);
	~Sphere();

	virtual bool hit(const Ray& r, HitRecord& hit) override;

private:
	Vec3f origin;
	float radius;
	float r2;
};