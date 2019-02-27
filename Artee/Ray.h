#pragma once

struct Ray
{
	vec3 origin;
	vec3 direction;

	/*
		Calculates the point along the direction of the direction

		Input:
			const float t		The distance along the direction the point is at

		Output:
			vec3				The coordinates of the point along the direction
	*/
	vec3 operator()(const float t)
	{
		return origin + direction * t;
	}
};