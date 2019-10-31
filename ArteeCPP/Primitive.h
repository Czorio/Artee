#pragma once
#include "Ray.h"
#include "HitRecord.h"

class Primitive
{
public:
	virtual ~Primitive() = default;

	virtual bool hit(const Ray& r, HitRecord& hit) = 0;
};
