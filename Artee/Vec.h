#pragma once

class vec3
{
public:
	union { struct { float x, y, z, dummy; }; float cell[4]; };

	vec3() = default;
	vec3(float v) : x(v), y(v), z(v) {}
	vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	vec3 operator - () const { return vec3(-x, -y, -z); }
	vec3 operator + (const vec3& addOperand) const { return vec3(x + addOperand.x, y + addOperand.y, z + addOperand.z); }
	vec3 operator - (const vec3& operand) const { return vec3(x - operand.x, y - operand.y, z - operand.z); }
	vec3 operator * (const vec3& operand) const { return vec3(x * operand.x, y * operand.y, z * operand.z); }

	void operator -= (const vec3& a) { x -= a.x; y -= a.y; z -= a.z; }
	void operator += (const vec3& a) { x += a.x; y += a.y; z += a.z; }
	void operator *= (const vec3& a) { x *= a.x; y *= a.y; z *= a.z; }
	void operator *= (const float a) { x *= a; y *= a; z *= a; }

	float operator [] (const unsigned& idx) const { return cell[idx]; }
	float& operator [] (const unsigned& idx) { return cell[idx]; }

	float length() const { return sqrtf(x * x + y * y + z * z); }
	float sqrLentgh() const { return x * x + y * y + z * z; }
	vec3 normalized() const { float r = 1.0f / length(); return vec3(x * r, y * r, z * r); }
	void normalize() { float r = 1.0f / length(); x *= r; y *= r; z *= r; }
	static vec3 normalize(const vec3 v) { return v.normalized(); }
	vec3 cross(const vec3& operand) const { return vec3(y * operand.z - z * operand.y, z * operand.x - x * operand.z, x * operand.y - y * operand.x); }
	float dot(const vec3& operand) const { return x * operand.x + y * operand.y + z * operand.z; }
};