#include "Camera.h"

Camera::Camera(Vec3f origin, Vec3f forward, Vec3f upGuide, float fov, float aperture, int x, int y)
{
	this->origin = origin;
	this->forward = forward;
	this->right = forward.cross(upGuide);
	this->up = right.cross(forward);
	this->fov = fov;
	this->aperture = aperture;
	this->aspect = (float)x / (float)y;
	this->x_size = x;
	this->y_size = y;
}

Camera::~Camera()
{
}

Ray Camera::getRayFor(int x, int y)
{
	Ray r = Ray();
	r.origin = origin;
	
	float u = (float)x / (float)x_size;
	float v = (float)y / (float)y_size;
	Vec3f to = origin + forward * fov + right * -u * aspect + up * v;
	r.direction = to - origin;

	return r;
}
