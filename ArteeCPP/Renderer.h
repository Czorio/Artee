#pragma once
#include "Camera.h"
#include <SDL2/SDL.h>

class Renderer
{
public:
	Renderer(int imageWidth, int imageHeight, const Camera& camera);
	~Renderer();

	// Rendering
	void renderFrame();
	void getOutput(uint32_t* pixels) const;

private:
	int imageWidth_;
	int imageHeight_;

	Vec3f* vecBuffer_;

	Camera camera_;

	static Vec3f shootRay(const Ray& r);
};
