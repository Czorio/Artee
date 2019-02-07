#pragma once

struct Ray
{
	vec3 origin;
	vec3 direction;

	vec3 operator()(const float t)
	{
		return origin + direction * t;
	}
};