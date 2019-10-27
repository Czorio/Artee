#pragma once
#include "Ray.h"
#include "HitRecord.h"

class Primitive
{
public:
	virtual ~Primitive() {}

	virtual bool hit(const Ray& r, HitRecord& hit) = 0;
};