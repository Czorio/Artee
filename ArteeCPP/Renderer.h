#pragma once
#include "Camera.h"
#include "Primitive.h"
#include <SDL2/SDL.h>
#include <vector>

class Renderer
{
public:
	Renderer(int imageWidth, int imageHeight, const Camera& camera);
	~Renderer();

	// Init
	void primitiveAdd(Primitive* primitive);
	void primitiveAdd(const std::vector<Primitive*>& primitives);
	
	// Rendering
	void renderFrame();
	void getOutput(uint32_t* pixels) const;

private:
	int imageWidth_;
	int imageHeight_;

	Vec3f* vecBuffer_;

	Camera camera_;
	std::vector<Primitive*> primitives_;

	Vec3f shootRay(const Ray& r);
};
