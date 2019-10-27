#pragma once
#include "Ray.h"

class Camera
{
	Camera();
	Camera(Vec3f origin, Vec3f forward, Vec3f upGuide, float fov, float aperture, int x, int y);
	~Camera();

	Ray getRayFor(int x, int y);

private:
	// Position
	Vec3f origin;

	// Direction
	Vec3f forward;
	Vec3f up;
	Vec3f right;

	// Camera
	float aspect;
	float fov;
	float aperture;
	float x_size;
	float y_size;
};

