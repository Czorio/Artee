#pragma once
#include "Camera.h"
#include <SDL2/SDL.h>

class Renderer
{
public:
	Renderer(int imageWidth, int imageHeight, Camera camera);
	~Renderer();

	// Rendering
	void renderFrame();
	void getOutput(uint32_t* pixels);

private:
	int imageWidth;
	int imageHeight;

	Vec3f* vecBuffer;

	Camera camera;

	Vec3f shootRay(const Ray& r);
};

