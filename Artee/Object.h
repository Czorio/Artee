#pragma once

class Object
{
public:
	Hit intersect(const Ray& r) const;

private:
	vec3 origin;
	// TODO: Replace with an accelleration structure
	std::vector<Primitive*> primitives;
};