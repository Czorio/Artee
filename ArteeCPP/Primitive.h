#pragma once
#include "Ray.h"
#include "HitRecord.h"

class Primitive
{
public:
	virtual ~Primitive() = default;

	virtual void translate(const Vec3f& translation) = 0;
	virtual bool hit(const Ray& r, HitRecord& hit) = 0;
};
