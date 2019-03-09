#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	Hit intersect(const Ray& r) const;

private:
	// TODO: Replace with an accelleration structure
	std::vector<Object*> Objects;
};