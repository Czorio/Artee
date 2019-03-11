#pragma once

// Axis Alligned Bounding Box
struct AABB
{
	vec3 min = vec3(FLT_MAX);
	vec3 max = vec3(FLT_MIN);
};