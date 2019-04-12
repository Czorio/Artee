#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	Hit intersect(const Ray& r) const;

private:
	BVH bvh;
};