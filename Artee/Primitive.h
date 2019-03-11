#pragma once

class Primitive
{
public:
	virtual Hit intersect(const Ray& r) const = 0;

private:

};

class Sphere : Primitive
{
	Hit intersect(const Ray& r) const override
	{

	}
};