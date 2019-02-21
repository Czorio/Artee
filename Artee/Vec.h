#pragma once

class vec3
{
public:
	union { struct { float x, y, z, dummy; }; __m128 cell; };

	vec3() = default;
	vec3(float v) : x(v), y(v), z(v) {}
	vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	vec3(__m128 cell) : cell(cell) {}

	vec3 operator - () const;
	vec3 operator + (const vec3& addOperand) const;
	vec3 operator - (const vec3& operand) const;
	vec3 operator * (const vec3& operand) const;
	
	void operator -= (const vec3& a);
	void operator += (const vec3& a);
	void operator *= (const vec3& a);
	void operator *= (const float a);

	float length() const;
	float sqrLentgh() const;
	vec3 normalized() const;
	void normalize();
	static vec3 normalize(const vec3 v);
	vec3 cross(const vec3& operand) const;
	float dot(const vec3& operand) const;
};