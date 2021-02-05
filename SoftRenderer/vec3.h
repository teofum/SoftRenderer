#pragma once

class vec3 {
public:
	double x, y, z;

	// Constructors --------------------------------

	vec3()
		:x(0), y(0), z(0) { };

	vec3(double x, double y, double z)
		:x(x), y(y), z(z) { };

	vec3(const vec3& v)
		:x(v.x), y(v.y), z(v.z) { };

	vec3(vec3&& v) noexcept
		:x(v.x), y(v.y), z(v.z) { };

	// Assignment operators ------------------------

	vec3& operator=(const vec3& v);
	vec3& operator=(vec3&& v) noexcept;

	// Comparison operators ------------------------

	bool operator==(const vec3& v) const;
	bool operator!=(const vec3& v) const;

	// Unary operators -----------------------------

	vec3 operator-() const;

	// Arithmetic operators (vec3) -----------------

	vec3 operator+(const vec3&) const;
	vec3 operator-(const vec3&) const;
	vec3 operator*(const vec3&) const;
	vec3 operator/(const vec3&) const;

	// Arithmetic operators (double) ----------------

	vec3 operator*(const double&) const;
	vec3 operator/(const double&) const;

	// Additional methods --------------------------

	double length() const;
	double length2() const;
	vec3 normalized() const;
	double dot(const vec3&) const;
	vec3 cross(const vec3&) const;
};