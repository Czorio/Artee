#pragma once
#include "Primitive.h"

class Triangle final : public Primitive
{
public:
	Triangle();
	Triangle(const Vec3f& v1, const Vec3f& v2, const Vec3f& v3, const Vec3f& norm);
	~Triangle() = default;

	bool hit(const Ray& r, HitRecord& hit) override;
private:
	// Verteces
	Vec3f v1_;
	Vec3f v2_;
	Vec3f v3_;

	// Edges
	Vec3f v1_v2_;
	Vec3f v1_v3_;

	// Normal
	Vec3f norm_;
};
