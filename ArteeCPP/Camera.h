#pragma once
#include "Ray.h"

class Camera
{
public:
	Camera();
	Camera(const Vec3f& origin, const Vec3f& forward, const Vec3f& upGuide, float fov, float aperture, int x, int y);
	~Camera() = default;

	Ray getRayFor(int x, int y) const;

private:
	// Position
	Vec3f origin_;

	// Direction
	Vec3f forward_;
	Vec3f up_;
	Vec3f right_;

	// Camera
	float aspect_;
	float fov_;
	float aperture_;
	float xSize_;
	float ySize_;
};
