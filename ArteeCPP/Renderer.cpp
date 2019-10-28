#include "Renderer.h"

Renderer::Renderer(int imageWidth, int imageHeight, Camera camera)
{
	this->camera = camera;
	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	vecBuffer = new Vec3f[imageWidth * imageHeight];
}

Renderer::~Renderer()
{
	delete[] vecBuffer;
	vecBuffer = NULL;
}

void Renderer::renderFrame()
{
	for (size_t y = 0; y < imageHeight; y++)
	{
		for (size_t x = 0; x < imageWidth; x++)
		{
			Ray r = camera.getRayFor(x, y);
			vecBuffer[y * imageWidth + x] = shootRay(r);
		}
	}
}

union Colour
{
	uint32_t integer;
	char chars[4];
};

constexpr float clamp(float hi, float lo, float val)
{
	if (val < lo)
	{
		return lo;
	}
	else if (val > hi)
	{
		return hi;
	}
	else
	{
		return val;
	}
}

void Renderer::getOutput(uint32_t* pixels)
{
	Colour c;

	int length = imageHeight * imageWidth;
	for (size_t i = 0; i < length; i++)
	{
		c.chars[0] = (char)(vecBuffer[i][0] * 255.f);
		c.chars[1] = (char)(vecBuffer[i][1] * 255.f);
		c.chars[2] = (char)(vecBuffer[i][2] * 255.f);
		c.chars[3] = 255;
		pixels[i] = c.integer;
	}
}

Vec3f Renderer::shootRay(const Ray& r)
{
	return Vec3f();
}
