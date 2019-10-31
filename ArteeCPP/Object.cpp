#include "Object.h"

Object::Object()
{
	primitives_ = std::vector<Primitive*>();
}

Object::Object(const std::vector<Primitive*>& primitives)
{
	this->origin_ = Vec3f();
	this->primitives_ = primitives;

	for (auto primitive : primitives_)
	{
		primitive->translate(origin_);
	}
}

Object::Object(const Vec3f& origin, const std::vector<Primitive*>& primitives)
{
	this->origin_ = origin;
	this->primitives_ = primitives;

	for (auto primitive : primitives_)
	{
		primitive->translate(origin_);
	}
}

bool Object::hit(const Ray& r, HitRecord& hitRecord)
{
	auto hasHit = false;

	HitRecord tempHit;
	for (auto primitive : primitives_)
	{
		if (primitive->hit(r, tempHit))
		{
			hasHit = true;
			if (hitRecord.distance > tempHit.distance)
			{
				hitRecord = tempHit;
			}
		}
	}

	return hasHit;
}

void Object::translate(const Vec3f& translation)
{
	this->origin_ += translation;

	for (auto primitive : primitives_)
	{
		primitive->translate(origin_);
	}
}
