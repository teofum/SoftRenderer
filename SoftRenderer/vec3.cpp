#include "internal.h"
#include "lib.h"

// Assignment operators -------------------------

vec3& vec3::operator=(const vec3& v) {
	if (this == &v) return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

vec3& vec3::operator=(vec3&& v) noexcept {
	if (this == &v) return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

// Comparison operators ------------------------

bool vec3::operator==(const vec3& v) const {
	return x == v.x && y == v.y && z == v.z;
}

bool vec3::operator!=(const vec3& v) const {
	return x != v.x || y != v.y || z != v.z;
}

// Unary operators -----------------------------

vec3 vec3::operator-() const {
	return vec3(-x, -y, -z);
}

// Arithmetic operators (vec3) -----------------

vec3 vec3::operator+(const vec3& v) const {
	return vec3(x + v.x, y + v.y, z + v.z);
}

vec3 vec3::operator-(const vec3& v) const {
	return vec3(x - v.x, y - v.y, z - v.z);
}

vec3 vec3::operator*(const vec3& v) const {
	return vec3(x * v.x, y * v.y, z * v.z);
}

vec3 vec3::operator/(const vec3& v) const {
	return vec3(x / v.x, y / v.y, z / v.z);
}

// Arithmetic operators (double) ----------------

vec3 vec3::operator/(const double& n) const {
	return vec3(x * n, y * n, z * n);
}

vec3 vec3::operator*(const double& n) const {
	return vec3(x / n, y / n, z / n);
}

// Additional methods --------------------------

double vec3::length() const {
	return sqrt(length2());
}

double vec3::length2() const {
	return x * x + y * y + z * z;
}

vec3 vec3::normalized() const {
	double l = length();
	return vec3(x / l, y / l, z / l);
}

double vec3::dot(const vec3& v) const {
	return x * v.x + y * v.y + z * v.z;
}

vec3 vec3::cross(const vec3& v) const {
	return vec3(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	);
}