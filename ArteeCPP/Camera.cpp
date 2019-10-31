#include "Camera.h"

Camera::Camera()
{
	origin_ = forward_ = up_ = right_ = Vec3f();
	aspect_ = fov_ = aperture_ = xSize_ = ySize_ = 0.f;
}

Camera::Camera(const Vec3f& origin, const Vec3f& forward, const Vec3f& upGuide, float fov, float aperture, int x, int y)
{
	this->origin_ = origin;
	this->forward_ = forward;
	this->right_ = forward.cross(upGuide);
	this->up_ = right_.cross(forward);
	this->fov_ = fov;
	this->aperture_ = aperture;
	this->aspect_ = float(x) / float(y);
	this->xSize_ = x;
	this->ySize_ = y;
}

Ray Camera::getRayFor(int x, int y) const
{
	auto r = Ray();
	r.origin = origin_;

	const auto u = float(x) / float(xSize_);
	const auto v = float(y) / float(ySize_);
	const auto to = origin_ + forward_ * fov_ + right_ * -u * aspect_ + up_ * v;
	r.direction = to - origin_;

	return r;
}
