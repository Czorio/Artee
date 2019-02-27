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

	/*
		Gets the length of the vector. Uses a sqrt(), which is not great for performance.

		Output:
			const float		The length of the vector
	*/
	float length() const;

	/*
		Gets the squared length of the vector. Does not use a sqrt().

		Output:
			const float		The squared length of the vector
	*/
	float sqrLentgh() const;

	/*
		Returns a copy of the vector, which has been normalized

		Output:
			const vec3		The normalized vector
	*/
	vec3 normalized() const;

	/*
		Normalizes the vector.
	*/
	void normalize();

	/*
		Normalizes a given vector

		Input:
			const vec3 v		The vector to normalize

		Output:
			vec3				The normalized vector
	*/
	static vec3 normalize(const vec3 v);

	/*
		Calculates cross product between two vectors

		Input:
			const vec3& operand		Other vector

		Output:
			const vec3				The result of the cross product
	*/
	vec3 cross(const vec3& operand) const;

	/*
		Calculates a dot product between two vectors. Equal to cos(theta) where theta is the angle between two vectors

		Input:
			const vec3& operand		Other vector

		Output:
			const float				The result of the dot product
	*/
	float dot(const vec3& operand) const;
};