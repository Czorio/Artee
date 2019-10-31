#pragma once
#include "Primitive.h"
#include <vector>

class Object : public Primitive
{
public:
	Object();
	explicit Object(const std::vector<Primitive*>& primitives);
	explicit Object(const Vec3f& origin, const std::vector<Primitive*>& primitives);
	virtual ~Object() = default;

	bool hit(const Ray& r, HitRecord& hitRecord) override;

	void translate(const Vec3f& translation) override;
private:
	Vec3f origin_;
	std::vector<Primitive*> primitives_;
};

