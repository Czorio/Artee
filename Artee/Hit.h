#pragma once
struct Hit
{
	// Hit properties
	int type = 0;
	float t = FLT_MAX;
	vec3 coordinates;
	vec3 normal;

	// Material properties
	vec3 color;
	float reflectivity;
	float refractivity;
};