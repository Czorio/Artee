#include "Renderer.h"

Renderer::Renderer(int imageWidth, int imageHeight, const Camera& camera)
{
	this->camera_ = camera;
	this->imageWidth_ = imageWidth;
	this->imageHeight_ = imageHeight;
	vecBuffer_ = new Vec3f[imageWidth * imageHeight];
}

Renderer::~Renderer()
{
	delete[] vecBuffer_;
	vecBuffer_ = nullptr;
}

void Renderer::renderFrame()
{
	for (size_t y = 0; y < imageHeight_; y++)
	{
		for (size_t x = 0; x < imageWidth_; x++)
		{
			auto r = camera_.getRayFor(x, y);
			vecBuffer_[y * imageWidth_ + x] = shootRay(r);
		}
	}
}

union Colour
{
	uint32_t integer;
	char chars[4];
};

constexpr float Clamp(const float hi, const float lo, const float val)
{
	if (val < lo)
	{
		return lo;
	}
	if (val > hi)
	{
		return hi;
	}
	return val;
}

void Renderer::getOutput(uint32_t* pixels) const
{
	Colour c;

	const auto length = imageHeight_ * imageWidth_;
	for (size_t i = 0; i < length; i++)
	{
		c.chars[0] = static_cast<char>(vecBuffer_[i][0] * 255.f);
		c.chars[1] = static_cast<char>(vecBuffer_[i][1] * 255.f);
		c.chars[2] = static_cast<char>(vecBuffer_[i][2] * 255.f);
		c.chars[3] = 255;
		pixels[i] = c.integer;
	}
}

Vec3f Renderer::shootRay(const Ray& r)
{
	return Vec3f();
}
