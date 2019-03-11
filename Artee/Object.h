#pragma once

class Object
{
public:
	Hit intersect(const Ray& r) const;
	void update(float deltaTime);

private:
	vec3 origin;
	// TODO: Replace with an accelleration structure
	BVH bvh;
};