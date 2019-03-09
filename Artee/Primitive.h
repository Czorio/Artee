#pragma once

class Primitive
{
	virtual Hit intersect(const Ray& r) const = 0;
};

class Sphere : Primitive
{
	Hit intersect(const Ray& r) const override;
};