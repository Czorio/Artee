#pragma once

/*
	A collection that can be defined as forming a complete "Object". Eg.: a rabbit, dragon, teapot, etc.
	Also handles movement such as animations or movements.
	The object has its own origin in the world, child primitives are thus in local space of the object.
*/
class Object
{
public:
	Object();
	~Object();

	/*
		Intersects a Ray with the object

		Input:
			const Ray& r		The ray to check intersections against
	*/
	Hit intersect(const Ray& r) const;

	/*
		Updates the state of the object, location, animation, etc.
		NOT IMPLEMENTED

		Input:
			float deltaTime		The elapsed time since the last update
	*/
	void update(float deltaTime);

private:
	vec3 origin;
	BVH bvh;
};